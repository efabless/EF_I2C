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

`timescale 1ns / 1ns 
`default_nettype none

module EF_I2C_WB #(
    parameter DEFAULT_PRESCALE = 1,
    parameter FIXED_PRESCALE = 0,
    parameter CMD_FIFO = 1,
    parameter CMD_FIFO_DEPTH = 16,
    parameter WRITE_FIFO = 1,
    parameter WRITE_FIFO_DEPTH = 16,
    parameter READ_FIFO = 1,
    parameter READ_FIFO_DEPTH = 16
) (

    input  wire        clk_i,
    input  wire        rst_i,
    input  wire [31:0] adr_i,
    input  wire [31:0] dat_i,
    output wire [31:0] dat_o,
    input  wire [ 3:0] sel_i,
    input  wire        cyc_i,
    input  wire        stb_i,
    output reg         ack_o,
    input  wire        we_i,
    output wire        IRQ,

    // I2C interface
    input  wire scl_i,
    output wire scl_o,
    output wire scl_oen_o,
    input  wire sda_i,
    output wire sda_o,
    output wire sda_oen_o

);

  localparam [15:0] RIS_REG_OFFSET = 16'hFF08;
  localparam [15:0] IM_REG_OFFSET = 16'hFF00;
  localparam [15:0] MIS_REG_OFFSET = 16'hFF04;
  localparam [15:0] GCLK_REG_OFFSET = 16'hFF10;

  reg [0:0] GCLK_REG;

  wire clk_g;
  wire clk_gated_en = GCLK_REG[0];

  ef_util_gating_cell clk_gate_cell (

      // USE_POWER_PINS
      .clk(clk_i),
      .clk_en(clk_gated_en),
      .clk_o(clk_g)
  );
  wire        clk = clk_g;
  wire        rst_n = ~rst_i;
  wire        wb_valid = cyc_i & stb_i;
  wire        wb_we = we_i & wb_valid;
  wire        wb_re = ~we_i & wb_valid;
  wire [ 3:0] wb_byte_sel = sel_i & {4{wb_we}};
  wire        rst = rst_i;
  wire [15:0] wbs_dat_o;
  wire        wbs_ack_o;
  wire        wbs_stb_i;

  wire [15:0] flags;
  reg  [ 8:0] IM_REG;
  wire [ 8:0] RIS_REG = {flags[15:8], flags[3]};
  wire [ 8:0] MIS_REG = RIS_REG & IM_REG;

  reg         i2c_ack_o;  // for registers outside the i2c master module

  assign dat_o = (adr_i[15:8] != 8'hFF)          ? {16'b0, wbs_dat_o}:
                    (adr_i[15:0] == RIS_REG_OFFSET)   ? {23'b0, RIS_REG}  :
                    (adr_i[15:0] == MIS_REG_OFFSET)   ? {23'b0, MIS_REG}  :
                    (adr_i[15:0] == IM_REG_OFFSET)    ? {23'b0, IM_REG}   :
                    (adr_i[15:0] == GCLK_REG_OFFSET)  ? {23'b0, GCLK_REG}   :
                    32'hDEADBEEF;
  assign ack_o = (adr_i[15:8] != 8'hFF) ? wbs_ack_o : i2c_ack_o;

  assign wbs_stb_i = (adr_i[15:8] != 8'hFF) ? stb_i : 1'b0;

  i2c_master_wbs_16 #(
      .DEFAULT_PRESCALE(DEFAULT_PRESCALE),
      .FIXED_PRESCALE(FIXED_PRESCALE),
      .CMD_FIFO(CMD_FIFO),
      .CMD_FIFO_DEPTH(CMD_FIFO_DEPTH),
      .WRITE_FIFO(WRITE_FIFO),
      .WRITE_FIFO_DEPTH(WRITE_FIFO_DEPTH),
      .READ_FIFO(READ_FIFO),
      .READ_FIFO_DEPTH(READ_FIFO_DEPTH)
  ) master_inst (
      .clk(clk),
      .rst(rst),

      /*
        * Host interface
        */
      .wbs_adr_i(adr_i[3:1]),  // ADR_I() address
      .wbs_dat_i(dat_i[15:0]),  // DAT_I() data in
      .wbs_dat_o(wbs_dat_o),  // DAT_O() data out
      .wbs_we_i(we_i),  // WE_I write enable input
      .wbs_sel_i(sel_i[1:0]),  // SEL_I() select input
      .wbs_stb_i(wbs_stb_i),  // STB_I strobe input
      .wbs_ack_o(wbs_ack_o),  // ACK_O acknowledge output
      .wbs_cyc_i(cyc_i),  // CYC_I cycle input

      // I2C interface
      .i2c_scl_i(scl_i),
      .i2c_scl_o(scl_o),
      .i2c_scl_t(scl_oen_o),
      .i2c_sda_i(sda_i),
      .i2c_sda_o(sda_o),
      .i2c_sda_t(sda_oen_o),

      .flags(flags)
  );

  always @(posedge clk_i or posedge rst_i)
    if (rst_i) GCLK_REG <= 0;
    else if (wb_we & (adr_i[16-1:0] == GCLK_REG_OFFSET)) GCLK_REG <= dat_i[1-1:0];

  always @(posedge clk_i or posedge rst_i)
    if (rst_i) IM_REG <= 0;
    else if (wb_we & (adr_i[16-1:0] == IM_REG_OFFSET)) IM_REG <= dat_i[9-1:0];

  always @(posedge clk_i or posedge rst_i)
    if (rst_i) i2c_ack_o <= 1'b0;
    else if (wb_valid & ~i2c_ack_o) i2c_ack_o <= 1'b1;
    else i2c_ack_o <= 1'b0;

  assign IRQ = |MIS_REG;

endmodule
