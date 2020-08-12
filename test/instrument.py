'''
This script is written to measure the noise in the envoirnment.
The instrument used in this case is Keysight DSOX1204G.
NOTE: In addition to pyvisa, pyusb and pyvisa-py is also required to run the script.
'''
import pyvisa as visa

rm = visa.ResourceManager('@py')
inst = rm.open_resource('USB0::10893::918::CN58467173::0::INSTR')

# Display instrument on the console
print("Instrument: {inst}".format(inst = inst.query("*IDN?")))

inst.close()
