# Lucid Candy
A bare minimum 8 channel EEG board with TI ads1299 chip. It can be driven with any microcontroller with 3.3 logic. Multiple boards can be chained together to record with 16 or 24 channels. This repository includes KiCad files and SPI example.

## Disclaimer
It still needs a lot of improvement, professional guidance and review. In no way it's fully tested to perform under clinical setting. Please use basic principles to test and evaluate before using it. Any suggestion is highly appreciated: gian@bettermetoo.com

## Who should use it?
No one really should, but if you're a newbie in electronics, software, and neuroscience, and want to learn more by building, then this might be a thing for you. If you're just looking for an affortable EEG, there're better open source ones out there, such as [OpenBCI](https://openbci.com/)

## Files & Locations
|-- lucid_candy
|---- component_datasheet // important datasheet of the components used for the board  
|---- e_component         // all the KiCad pcb footprint (from SnapEDA) for the components  
|---- eeg                 // KiCad design files  
|---- firmware            // example of Arduino DUE communicating with the board via SPI  
|---- gerber_zip          // same file used to produce the current board with JLCPCB  
