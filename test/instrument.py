'''
SCPI script for Keysight DSOX1204G.
The purpose is to measure the noise in the envoirnment.
NOTE: In addition to pyvisa, pyusb and pyvisa-py is also required to run the script.
'''
import sys
import pyvisa as visa
import time

VISA_ADDRESS = "USB0::10893::918::CN58467173::0::INSTR"
GLOBAL_TIMEOUT = 10000 # Time in miliseconds
TIME_TO_TRIGGER = 10 # Time in seconds
TIME_BETWEEN_RIGGERS = 0.025 # Time in seconds
PROCESSING_TIME = 0 # Time in seconds
SCOPE_ACQUISITION_TIMEOUT = 14

rm = visa.ResourceManager('@py')
inst = rm.open_resource(VISA_ADDRESS)
# Display instrument on the console
print("Instrument: {inst}".format(inst = inst.query("*IDN?")))

# Set the global timeout
inst.timeout = GLOBAL_TIMEOUT
# Clear the instrument bus
inst.clear()
# Clear all registers and errors
clear_reg = inst.write("*CLS")
print("clearing registers...")
print(clear_reg)
# Reset the scope
reset = inst.write("*RST")
print("Resetting...")
print(reset)

# Stop the scope
stop_scope = inst.query(":STOP;*OPC?")
print("Stopping Scope...")
print(stop_scope)

# Smallest voltage per division setting
set_v_div = inst.write(":CHAN1:RANG .04")
print("Setting voltage per division...")
print(set_v_div)

# Set time per division, the range should be large enought to capture environment
set_t_div = inst.write(":TIM:SCALE 1e-2")
print("Setting time per division...")
print(set_t_div)

# Set up triggering
set_sweep_trig = inst.write(":TRIG:SWE TRIG")
print("Setting trigger mode...")
print(set_sweep_trig)
set_trig = inst.query(":TRIG:EDGE:SOUR LINE;*OPC?")
print("Setting trigger...")
print(set_trig)

# Clear the display
clear_display = inst.write(":CDIS")
print("Clearing display...")
print(clear_display)

# Acquire
acq = inst.query(":DIG;*OPC?")
print("Acquiring result...")
print(acq)

# Do something with the data
vpp_ch1 = str(inst.query("MEAS:VPP? CHAN1")).strip("\n")
print("vpp ch1 = " + vpp_ch1 + "V\n")

# Turn on AC RMS measurement
inst.clear()
inst.close()
