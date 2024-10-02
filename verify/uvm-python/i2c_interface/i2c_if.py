from uvm.base.sv import sv_if


class i2c_if(sv_if):
    def __init__(self, dut):
        bus_map = {"CLK": "CLK", "RESETn": "RESETn", "scl_pin": "scl_pin", "sda_pin": "sda_pin"}
        super().__init__(dut, "", bus_map)
