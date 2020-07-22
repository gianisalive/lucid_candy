# Lucid Candy
![board pic](github_resource/board.jpg)
A bare minimum 8 channel EEG board with TI ads1299 chip. It can be driven with any microcontroller that has 3.3V logic. Multiple boards can be chained together to record with 16 or 24 channels. This repository includes KiCad files and SPI example.

## Disclaimer
It still needs a lot of improvement, professional guidance and review. In no way it's fully tested to perform under clinical setting. Please use basic principles to test and evaluate before using it. All suggestions are highly appreciated: gian@bettermetoo.com

## Who should use it?
No one really should, but if you're a newbie in electronics, software, and neuroscience, and want to learn more by building, then this might be a thing for you. If you're just looking for an affortable EEG, there're better open source ones out there, such as [OpenBCI](https://openbci.com/).

## Files & Locations
|-- lucid_candy  
|---- component_datasheet------important datasheet of the components used for the board  
|---- e_component---------------all the KiCad pcb footprint (from SnapEDA) for the components  
|---- eeg------------------------KiCad design files  
|---- firmware-------------------example of Arduino DUE communicating with the board via SPI  
|---- gerber_zip-----------------same file used to produce the current board with JLCPCB  

## Schematics
The philosophy with current version of the design is to work within TI's recommendation, and choose components with least amount of tolerance/inductance to develope a baseline. In the future, any design improvement can be evaluated/compared to the current design.
![eeg_schematics](schematic/eeg.jpg)
![power_schematics](schematic/power.jpg)

## Components
All the component used can be found [here](https://docs.google.com/spreadsheets/d/1N4UGuHjUGolRgQoIL3MemhwEijfZmJlSR52b1LrSyF4/edit?usp=sharing). Some of these are pretty over priced. In most situations, you can probably get away with cheaper parts.

## Programming in a nutshell
**Overview:**  
- Data are transfered via SPI MODE1 with MSB first
- Data are retrieve with no-op command 0x00
- Chip has an internal clock. If BYOO (bring your own oscillator), then connect it to CLK pin, and tie CLKSEL low.  

**Power up sequence:**  
- Set CLKSEL pin high to enable internal oscillator
- Set RESET pin high, and make sure VCAP1 is settled around 1.1V
- Send reset command, and at this point DRDY pin should toggle at around 250Hz
- Send SDATAC (stop data continuous) command
- Set CONFIG1(0x01), CONFIG2(0x02) and CONFIG3(0x03)
- Set CHnSET (single ended, double ended or generate test signal)

**Data conversion:**  
- After sending RDATA or RDATAC command, data is returned on the second rising edge of the DRDY pin
- Initial 3 bytes are status data, and it always starts with 1100. Then it'll transfer 3 bytes of data per channel. An 8 channel board will have 8 * 3 + 3 = 27 bytes of data
- Data are structured in 2's compliment. The MSB is used to determin whether the value is positive or negative
- V = decimal value * (2 * 4.5 / 24) / (2 ^ 24)

## Testing
Fully assembled device with current Arduino firmware is tested with a Calibrated Keysight DSOX1204G oscilloscope/function generator.

## Miscellaneous
Some silly questions I asked:
 - [voltage offset](https://e2e.ti.com/support/data-converters/f/73/p/912858/3374371#3374371)
