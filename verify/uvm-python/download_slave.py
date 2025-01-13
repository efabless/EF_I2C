import requests
import zipfile
import os

# Step 1: Download the ZIP file
url = 'https://ww1.microchip.com/downloads/en/DeviceDoc/24xx64_Verilog_Model.zip'
zip_file_path = '24xx64_Verilog_Model.zip'
verilog_file_path = 'i2c_slaves/24AA64.v'
# exit if already exists
if os.path.exists(verilog_file_path):
    exit(0)
response = requests.get(url)
with open(zip_file_path, 'wb') as f:
    f.write(response.content)

# Step 2: Extract the ZIP file
with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
    zip_ref.extractall('i2c_slaves')

# Step 3: Edit the text file(s) inside
with open(verilog_file_path, 'r') as file:
    content = file.read()

# Modify the content (example: appending text)
old_verilog_code = """
   initial begin
      `ifdef VCC_1_7V_TO_2_5V
         tAA = 3500;                // SCL to SDA output delay
         tWC = 5000000;             // memory write cycle time
      `else
      `ifdef VCC_2_5V_TO_5_5V
         tAA = 900;                 // SCL to SDA output delay
         tWC = 5000000;             // memory write cycle time
      `else
         tAA = 900;                 // SCL to SDA output delay
         tWC = 5000000;             // memory write cycle time
      `endif
      `endif
   end
"""

# Define the new Verilog code
new_verilog_code = """
   initial begin
      `ifdef VCC_1_7V_TO_2_5V
         tAA = 0;                // SCL to SDA output delay
         tWC = 0;             // memory write cycle time
      `else
      `ifdef VCC_2_5V_TO_5_5V
         tAA = 0;                 // SCL to SDA output delay
         tWC = 0;             // memory write cycle time
      `else
         tAA = 0;                 // SCL to SDA output delay
         tWC = 0;             // memory write cycle time
      `endif
      `endif
   end
"""
# Save the changes
with open(verilog_file_path, 'w') as file:
    file.write(content.replace(old_verilog_code, new_verilog_code))

# Clean up (optional): Remove ZIP file after extraction
os.remove(zip_file_path)
