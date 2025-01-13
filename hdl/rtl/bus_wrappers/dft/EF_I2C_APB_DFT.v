/*
 Copyright 2024 Efabless Corp.
 
 Author: Efabless Corp. (ip_admin@efabless.com)
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 */

`timescale 1ns / 1ps
`default_nettype none

module EF_I2S_APB #(
    parameter DW = 32,
    AW = 4
) (

    input  wire         PCLK,
    input  wire         PRESETn,
    input  wire         PWRITE,
    input  wire [ 31:0] PWDATA,
    input  wire [ 31:0] PADDR,
    input  wire         PENABLE,
    input  wire         PSEL,
    output wire         PREADY,
    output wire [ 31:0] PRDATA,
    output wire         IRQ,
    output wire [1-1:0] ws,
    output wire [1-1:0] sck,
    input  wire [1-1:0] sdi,
    input  wire         sc_testmode
);

  localparam RXDATA_REG_OFFSET = 16'h0000;
  localparam PR_REG_OFFSET = 16'h0004;
  localparam AVGT_REG_OFFSET = 16'h0008;
  localparam ZCRT_REG_OFFSET = 16'h000C;
  localparam CTRL_REG_OFFSET = 16'h0010;
  localparam CFG_REG_OFFSET = 16'h0014;
  localparam RX_FIFO_LEVEL_REG_OFFSET = 16'hFE00;
  localparam RX_FIFO_THRESHOLD_REG_OFFSET = 16'hFE04;
  localparam RX_FIFO_FLUSH_REG_OFFSET = 16'hFE08;
  localparam IM_REG_OFFSET = 16'hFF00;
  localparam MIS_REG_OFFSET = 16'hFF04;
  localparam RIS_REG_OFFSET = 16'hFF08;
  localparam IC_REG_OFFSET = 16'hFF0C;

  reg [0:0] GCLK_REG;
  wire clk_g;
  // wire clk_gated_en = GCLK_REG[0];
  wire clk_gated_en = sc_testmode ? 1'b1 : GCLK_REG[0];
  ef_gating_cell clk_gate_cell (

      // USE_POWER_PINS
      .clk(PCLK),
      .clk_en(clk_gated_en),
      .clk_o(clk_g)
  );

  wire          clk = clk_g;
  wire          rst_n = PRESETn;

  wire          apb_valid = PSEL & PENABLE;
  wire          apb_we = PWRITE & apb_valid;
  wire          apb_re = ~PWRITE & apb_valid;

  wire [ 1-1:0] fifo_en;
  wire [ 1-1:0] fifo_rd;
  wire [AW-1:0] fifo_level_threshold;
  wire [ 1-1:0] fifo_flush;
  wire [ 1-1:0] fifo_full;
  wire [ 1-1:0] fifo_empty;
  wire [AW-1:0] fifo_level;
  wire [ 1-1:0] fifo_level_above;
  wire [32-1:0] fifo_rdata;
  wire [ 1-1:0] sign_extend;
  wire [ 1-1:0] left_justified;
  wire [ 6-1:0] sample_size;
  wire [ 8-1:0] sck_prescaler;
  wire [32-1:0] avg_threshold;
  wire [ 1-1:0] avg_flag;
  wire [ 1-1:0] avg_en;
  wire [ 1-1:0] avg_sel;
  wire [32-1:0] zcr_threshold;
  wire [ 1-1:0] zcr_flag;
  wire [ 1-1:0] zcr_en;
  wire [ 1-1:0] zcr_sel;
  wire [ 1-1:0] vad_flag;
  wire [ 2-1:0] channels;
  wire [ 1-1:0] en;

  // Register Definitions
  wire [32-1:0] RXDATA_WIRE;

  reg  [   7:0] PR_REG;
  assign sck_prescaler = PR_REG;
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) PR_REG <= 0;
    else if (apb_we & (PADDR[16-1:0] == PR_REG_OFFSET)) PR_REG <= PWDATA[8-1:0];

  reg [31:0] AVGT_REG;
  assign avg_threshold = AVGT_REG;
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) AVGT_REG <= 0;
    else if (apb_we & (PADDR[16-1:0] == AVGT_REG_OFFSET)) AVGT_REG <= PWDATA[32-1:0];

  reg [31:0] ZCRT_REG;
  assign zcr_threshold = ZCRT_REG;
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) ZCRT_REG <= 0;
    else if (apb_we & (PADDR[16-1:0] == ZCRT_REG_OFFSET)) ZCRT_REG <= PWDATA[32-1:0];

  reg [3:0] CTRL_REG;
  assign en = CTRL_REG[0 : 0];
  assign fifo_en = CTRL_REG[1 : 1];
  assign avg_en = CTRL_REG[2 : 2];
  assign zcr_en = CTRL_REG[3 : 3];
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) CTRL_REG <= 'h0;
    else if (apb_we & (PADDR[16-1:0] == CTRL_REG_OFFSET)) CTRL_REG <= PWDATA[4-1:0];

  reg [11:0] CFG_REG;
  assign channels = CFG_REG[1 : 0];
  assign sign_extend = CFG_REG[2 : 2];
  assign left_justified = CFG_REG[3 : 3];
  assign sample_size = CFG_REG[9 : 4];
  assign avg_sel = CFG_REG[10 : 10];
  assign zcr_sel = CFG_REG[11 : 11];
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) CFG_REG <= 'h201;
    else if (apb_we & (PADDR[16-1:0] == CFG_REG_OFFSET)) CFG_REG <= PWDATA[12-1:0];

  wire [AW-1:0] RX_FIFO_LEVEL_WIRE;
  assign RX_FIFO_LEVEL_WIRE[(AW-1) : 0] = fifo_level;

  reg [AW-1:0] RX_FIFO_THRESHOLD_REG;
  assign fifo_level_threshold = RX_FIFO_THRESHOLD_REG[(AW-1) : 0];
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) RX_FIFO_THRESHOLD_REG <= 0;
    else if (apb_we & (PADDR[16-1:0] == RX_FIFO_THRESHOLD_REG_OFFSET))
      RX_FIFO_THRESHOLD_REG <= PWDATA[AW-1:0];

  reg [0:0] RX_FIFO_FLUSH_REG;
  assign fifo_flush = RX_FIFO_FLUSH_REG[0 : 0];
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) RX_FIFO_FLUSH_REG <= 0;
    else if (apb_we & (PADDR[16-1:0] == RX_FIFO_FLUSH_REG_OFFSET))
      RX_FIFO_FLUSH_REG <= PWDATA[1-1:0];
    else RX_FIFO_FLUSH_REG <= 1'h0 & RX_FIFO_FLUSH_REG;

  localparam GCLK_REG_OFFSET = 16'hFF10;
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) GCLK_REG <= 0;
    else if (apb_we & (PADDR[16-1:0] == GCLK_REG_OFFSET)) GCLK_REG <= PWDATA[1-1:0];

  reg  [  5:0] IM_REG;
  reg  [  5:0] IC_REG;
  reg  [  5:0] RIS_REG;

  wire [6-1:0] MIS_REG = RIS_REG & IM_REG;
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) IM_REG <= 0;
    else if (apb_we & (PADDR[16-1:0] == IM_REG_OFFSET)) IM_REG <= PWDATA[6-1:0];
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) IC_REG <= 6'b0;
    else if (apb_we & (PADDR[16-1:0] == IC_REG_OFFSET)) IC_REG <= PWDATA[6-1:0];
    else IC_REG <= 6'd0;

  wire [0:0] FIFOE = fifo_empty;
  wire [0:0] FIFOA = fifo_level_above;
  wire [0:0] FIFOF = fifo_full;
  wire [0:0] AVGF = avg_flag;
  wire [0:0] ZCRF = zcr_flag;
  wire [0:0] VADF = vad_flag;

  integer _i_;
  always @(posedge PCLK or negedge PRESETn)
    if (~PRESETn) RIS_REG <= 0;
    else begin
      for (_i_ = 0; _i_ < 1; _i_ = _i_ + 1) begin
        if (IC_REG[_i_]) RIS_REG[_i_] <= 1'b0;
        else if (FIFOE[_i_-0] == 1'b1) RIS_REG[_i_] <= 1'b1;
      end
      for (_i_ = 1; _i_ < 2; _i_ = _i_ + 1) begin
        if (IC_REG[_i_]) RIS_REG[_i_] <= 1'b0;
        else if (FIFOA[_i_-1] == 1'b1) RIS_REG[_i_] <= 1'b1;
      end
      for (_i_ = 2; _i_ < 3; _i_ = _i_ + 1) begin
        if (IC_REG[_i_]) RIS_REG[_i_] <= 1'b0;
        else if (FIFOF[_i_-2] == 1'b1) RIS_REG[_i_] <= 1'b1;
      end
      for (_i_ = 3; _i_ < 4; _i_ = _i_ + 1) begin
        if (IC_REG[_i_]) RIS_REG[_i_] <= 1'b0;
        else if (AVGF[_i_-3] == 1'b1) RIS_REG[_i_] <= 1'b1;
      end
      for (_i_ = 4; _i_ < 5; _i_ = _i_ + 1) begin
        if (IC_REG[_i_]) RIS_REG[_i_] <= 1'b0;
        else if (ZCRF[_i_-4] == 1'b1) RIS_REG[_i_] <= 1'b1;
      end
      for (_i_ = 5; _i_ < 6; _i_ = _i_ + 1) begin
        if (IC_REG[_i_]) RIS_REG[_i_] <= 1'b0;
        else if (VADF[_i_-5] == 1'b1) RIS_REG[_i_] <= 1'b1;
      end
    end

  assign IRQ = |MIS_REG;

  reg [0:0] _sdi_reg_[1:0];
  wire _sdi_w_ = _sdi_reg_[1];
  always @(posedge PCLK or negedge PRESETn)
    if (PRESETn == 0) begin
      _sdi_reg_[0] <= 'b0;
      _sdi_reg_[1] <= 'b0;
    end else begin
      _sdi_reg_[0] <= sdi;
      _sdi_reg_[1] <= _sdi_reg_[0];
    end
  EF_I2S #(
      .DW(DW),
      .AW(AW)
  ) instance_to_wrap (
      .clk(clk),
      .rst_n(rst_n),
      .fifo_en(fifo_en),
      .fifo_rd(fifo_rd),
      .fifo_level_threshold(fifo_level_threshold),
      .fifo_flush(fifo_flush),
      .fifo_full(fifo_full),
      .fifo_empty(fifo_empty),
      .fifo_level(fifo_level),
      .fifo_level_above(fifo_level_above),
      .fifo_rdata(fifo_rdata),
      .sign_extend(sign_extend),
      .left_justified(left_justified),
      .sample_size(sample_size),
      .sck_prescaler(sck_prescaler),
      .avg_threshold(avg_threshold),
      .avg_flag(avg_flag),
      .avg_en(avg_en),
      .avg_sel(avg_sel),
      .zcr_threshold(zcr_threshold),
      .zcr_flag(zcr_flag),
      .zcr_en(zcr_en),
      .zcr_sel(zcr_sel),
      .vad_flag(vad_flag),
      .channels(channels),
      .en(en),
      .ws(ws),
      .sck(sck),
      .sdi(_sdi_w_)
  );

  assign	PRDATA = 
			(PADDR[16-1:0] == RXDATA_REG_OFFSET)	? RXDATA_WIRE :
			(PADDR[16-1:0] == PR_REG_OFFSET)	? PR_REG :
			(PADDR[16-1:0] == AVGT_REG_OFFSET)	? AVGT_REG :
			(PADDR[16-1:0] == ZCRT_REG_OFFSET)	? ZCRT_REG :
			(PADDR[16-1:0] == CTRL_REG_OFFSET)	? CTRL_REG :
			(PADDR[16-1:0] == CFG_REG_OFFSET)	? CFG_REG :
			(PADDR[16-1:0] == RX_FIFO_LEVEL_REG_OFFSET)	? RX_FIFO_LEVEL_WIRE :
			(PADDR[16-1:0] == RX_FIFO_THRESHOLD_REG_OFFSET)	? RX_FIFO_THRESHOLD_REG :
			(PADDR[16-1:0] == RX_FIFO_FLUSH_REG_OFFSET)	? RX_FIFO_FLUSH_REG :
			(PADDR[16-1:0] == IM_REG_OFFSET)	? IM_REG :
			(PADDR[16-1:0] == MIS_REG_OFFSET)	? MIS_REG :
			(PADDR[16-1:0] == RIS_REG_OFFSET)	? RIS_REG :
			(PADDR[16-1:0] == IC_REG_OFFSET)	? IC_REG :
			(PADDR[16-1:0] == GCLK_REG_OFFSET)	? GCLK_REG :
			32'hDEADBEEF;

  assign PREADY = 1'b1;

  assign RXDATA_WIRE = fifo_rdata;
  assign fifo_rd = (apb_re & (PADDR[16-1:0] == RXDATA_REG_OFFSET));
endmodule
