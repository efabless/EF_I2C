PLUSARGS += "+UVM_VERBOSITY=UVM_MEDUIM"
TOPLEVEL := top
MODULE   ?= top_module
AHB_FILES ?= # TODO: Add add AHB wrapper file path
APB_FILES ?= $(PWD)/../../hdl/rtl/bus_wrappers/EF_I2C_APB.v
WB_FILES ?= $(PWD)/../../hdl/rtl/bus_wrappers/EF_I2C_WB.v
HDL_FILES ?= $(PWD)/../../ip/EF_IP_UTIL/hdl/ef_util_lib.v $(PWD)/../../hdl/rtl/i2c_master_wbs_16.v  $(PWD)/../../hdl/rtl/i2c_master.v $(PWD)/../../hdl/rtl/axis_fifo.v
VIP_FILES ?= $(PWD)/i2c_slaves/24AA64.v
VERILOG_SOURCES ?=  $(PWD)/top.v $(AHB_FILES) $(APB_FILES) $(WB_FILES) $(HDL_FILES) $(VIP_FILES)
RTL_MACROS += "" # Add macros needed
BUS_TYPE ?= APB
ifeq ($(BUS_TYPE),APB)
    RTL_MACROS += -DBUS_TYPE_APB
    DESIGN_NAME = EF_I2C_APB
    export CLK_MAKEFILE = PCLK
    export RST_MAKEFILE = PRESETn
else ifeq ($(BUS_TYPE),AHB)
    RTL_MACROS += -DBUS_TYPE_AHB
    DESIGN_NAME = EF_I2C_AHBL
    export CLK_MAKEFILE = HCLK
    export RST_MAKEFILE = HRESETn
else ifeq ($(BUS_TYPE),WISHBONE)
    RTL_MACROS += -DBUS_TYPE_WISHBONE
    DESIGN_NAME = EF_I2C_WB
    export CLK_MAKEFILE = clk_i
    export RST_MAKEFILE = rst_i

endif
## netlist Gen 
GL_MACROS += -DGL -DFUNCTIONAL  $(RTL_MACROS) -DUNIT_DELAY=\#1 
PRE_SYS_FILES = $(AHB_FILES) $(APB_FILES) $(WB_FILES) $(HDL_FILES)
PDK_DIR = $(HOME)/.volare/volare/sky130/versions/bdc9412b3e468c102d01b7cf6337be06ec6e9c9a/sky130A/
PDK_FILES = $(PDK_DIR)/libs.ref/sky130_fd_sc_hd/verilog/primitives.v $(PDK_DIR)/libs.ref/sky130_fd_sc_hd/verilog/sky130_fd_sc_hd.v # get this from openlane logs in the future 
# IPM_DIR = $(HOME)/.ipm
POST_SYS_FILES = $(PWD)/top.v $(VIP_FILES) $(PWD)/../../hdl/gl/synthesis/nl/$(DESIGN_NAME).nl.v


# RTL_MACROS ?= "-DSKIP_WAVE_DUMP"
YAML_FILE = $(PWD)/../../EF_I2C.yaml 
MAKEFLAGS += --no-print-directory

# List of tests
TESTS := i2c_write_read_test i2c_write_mul_test WriteReadRegsTest

# Variable for tag - set this as required
SIM_TAG ?= default_tag

# Define SIM_PATH variable
SIM_PATH := $(PWD)/sim/$(SIM_TAG)

# Check and clone EF_UVM repository at the beginning of the Makefile execution

clone_ef_uvm := $(shell if [ ! -d "EF_UVM" ]; then \
	echo "Cloning the EF_UVM repository..."; \
	git clone https://github.com/efabless/EF_UVM.git; \
fi;)

slave_download := $(shell python3 $(PWD)/download_slave.py)

include EF_UVM/Makefile.test
