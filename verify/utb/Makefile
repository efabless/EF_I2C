# Makefile for compiling and running a testbench with RTL files using VCS

# Compiler and simulation settings
PDK_ROOT ?= ""
MGMT_ROOT ?= ""


PDK ?= sky130A
TB_TOP = EF_I2C_APB_tb
IV_RTL_FILES = -c ./$(TB_TOP).f
IV_FLAGS = -DCOCOTB_SIM -DFUNCTIONAL -DUNIT_DELAY=\#1
# PDK_INCLUDES = $(PDK_ROOT)/$(PDK)/libs.ref/sky130_fd_sc_hd/verilog/sky130_fd_sc_hd.v $(PDK_ROOT)/$(PDK)/libs.ref/sky130_fd_sc_hd/verilog/primitives.v 
TB_LOG = simulation.log
RUN_LOG = run.log

$(TB_TOP).v:
	@echo "Error: Testbench source file not found!"
	@exit 1

clean:
	rm -rf $(TB_LOG) $(RUN_LOG) *.vcd *.vvp

sim-rtl: $(TB_TOP).v $(PDK_INCLUDES)
	iverilog -o $(TB_TOP)-rtl.vvp -s $(TB_TOP) $(IV_FLAGS) $(TB_TOP).v $(IV_RTL_FILES) $(PDK_INCLUDES) > $(TB_LOG)
	./$(TB_TOP)-rtl.vvp > $(RUN_LOG)