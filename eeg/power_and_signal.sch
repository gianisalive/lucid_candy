EESchema Schematic File Version 4
LIBS:eeg-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Regulator_Linear:ADP7182ACPZN U?
U 1 1 5D8DA0D1
P 2800 3750
AR Path="/5D8DA0D1" Ref="U?"  Part="1" 
AR Path="/5D6FC2AC/5D8DA0D1" Ref="U2"  Part="1" 
F 0 "U2" H 2800 3475 50  0000 C CNN
F 1 "ADP7182ACPZN-2.5" H 2800 3384 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:Analog_TSOT-5" H 2800 3350 50  0001 C CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADP7182.pdf" H 2800 3250 50  0001 C CNN
	1    2800 3750
	-1   0    0    1   
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5D8DA0D7
P 2800 4150
AR Path="/5D8DA0D7" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5D8DA0D7" Ref="#PWR0114"  Part="1" 
F 0 "#PWR0114" H 2800 3900 50  0001 C CNN
F 1 "GNDA" H 2805 3977 50  0000 C CNN
F 2 "" H 2800 4150 50  0001 C CNN
F 3 "" H 2800 4150 50  0001 C CNN
	1    2800 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D8DA0DD
P 3400 3900
AR Path="/5D8DA0DD" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D8DA0DD" Ref="C7"  Part="1" 
F 0 "C7" H 3515 3946 50  0000 L CNN
F 1 "2.2uF" H 3515 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3438 3750 50  0001 C CNN
F 3 "~" H 3400 3900 50  0001 C CNN
	1    3400 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D8DA0E3
P 2200 3900
AR Path="/5D8DA0E3" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D8DA0E3" Ref="C8"  Part="1" 
F 0 "C8" H 2315 3946 50  0000 L CNN
F 1 "2.2uF" H 2315 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2238 3750 50  0001 C CNN
F 3 "~" H 2200 3900 50  0001 C CNN
	1    2200 3900
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 3650 2200 3650
Wire Wire Line
	2200 3750 2200 3650
Connection ~ 2200 3650
Wire Wire Line
	2200 3650 1850 3650
Wire Wire Line
	3400 3750 3400 3650
Wire Wire Line
	3400 3650 3250 3650
$Comp
L Regulator_Linear:ADM7160AUJZ U?
U 1 1 5D8DD35F
P 4750 5050
AR Path="/5D8DD35F" Ref="U?"  Part="1" 
AR Path="/5D6FC2AC/5D8DD35F" Ref="U3"  Part="1" 
F 0 "U3" H 4750 4775 50  0000 C CNN
F 1 "ADM7160AUJZ2.5" H 4750 4684 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:Analog_TSOT-5" H 4750 4650 50  0001 C CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADP7182.pdf" H 4750 4550 50  0001 C CNN
	1    4750 5050
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5D8DD365
P 4200 4750
AR Path="/5D8DD365" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D8DD365" Ref="C4"  Part="1" 
F 0 "C4" H 4315 4796 50  0000 L CNN
F 1 "4.7uF" H 4315 4705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 4600 50  0001 C CNN
F 3 "~" H 4200 4750 50  0001 C CNN
	1    4200 4750
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5D8DD36B
P 4950 5650
AR Path="/5D8DD36B" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D8DD36B" Ref="C5"  Part="1" 
F 0 "C5" H 5065 5696 50  0000 L CNN
F 1 "4.7uF" H 5065 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4988 5500 50  0001 C CNN
F 3 "~" H 4950 5650 50  0001 C CNN
	1    4950 5650
	-1   0    0    1   
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5D8DD377
P 4750 4550
AR Path="/5D8DD377" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5D8DD377" Ref="#PWR0115"  Part="1" 
F 0 "#PWR0115" H 4750 4300 50  0001 C CNN
F 1 "GNDA" H 4755 4377 50  0000 C CNN
F 2 "" H 4750 4550 50  0001 C CNN
F 3 "" H 4750 4550 50  0001 C CNN
	1    4750 4550
	-1   0    0    1   
$EndComp
Wire Wire Line
	4350 4950 4200 4950
Wire Wire Line
	4200 4900 4200 4950
Connection ~ 4200 4950
Wire Wire Line
	4200 4950 3650 4950
$Comp
L Regulator_Linear:ADM7160AUJZ U?
U 1 1 5D938FAD
P 6450 3750
AR Path="/5D938FAD" Ref="U?"  Part="1" 
AR Path="/5D6FC2AC/5D938FAD" Ref="U4"  Part="1" 
F 0 "U4" H 6450 3475 50  0000 C CNN
F 1 "ADM7160AUJZ23.3" H 6450 3384 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:Analog_TSOT-5" H 6450 3350 50  0001 C CIN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ADP7182.pdf" H 6450 3250 50  0001 C CNN
	1    6450 3750
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5D938FB3
P 5900 3450
AR Path="/5D938FB3" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D938FB3" Ref="C2"  Part="1" 
F 0 "C2" H 6015 3496 50  0000 L CNN
F 1 "4.7uF" H 6015 3405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5938 3300 50  0001 C CNN
F 3 "~" H 5900 3450 50  0001 C CNN
	1    5900 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	6850 3650 6850 3250
$Comp
L power:GNDA #PWR?
U 1 1 5D938FC5
P 6850 3150
AR Path="/5D938FC5" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5D938FC5" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 6850 2900 50  0001 C CNN
F 1 "GNDA" H 6855 2977 50  0000 C CNN
F 2 "" H 6850 3150 50  0001 C CNN
F 3 "" H 6850 3150 50  0001 C CNN
	1    6850 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	6050 3650 5900 3650
Wire Wire Line
	5900 3600 5900 3650
Connection ~ 5900 3650
Wire Wire Line
	5900 3300 5900 3250
Wire Wire Line
	3200 3850 3250 3850
Wire Wire Line
	3250 3850 3250 3650
Connection ~ 3250 3650
Wire Wire Line
	3250 3650 3200 3650
Wire Wire Line
	6625 4500 6625 4650
$Comp
L Device:D D1
U 1 1 5D984FB2
P 6800 4500
F 0 "D1" H 6800 4624 50  0000 C CNN
F 1 "D" H 6800 4375 50  0001 C CNN
F 2 "Diode_SMD:D_SOD-523" H 6800 4500 50  0001 C CNN
F 3 "~" H 6800 4500 50  0001 C CNN
	1    6800 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5D975AF1
P 3600 3200
AR Path="/5D975AF1" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5D975AF1" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 3600 2950 50  0001 C CNN
F 1 "GNDA" H 3605 3027 50  0000 C CNN
F 2 "" H 3600 3200 50  0001 C CNN
F 3 "" H 3600 3200 50  0001 C CNN
	1    3600 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	3600 3500 3600 3650
$Comp
L Device:C C?
U 1 1 5D959BF1
P 3600 3350
AR Path="/5D959BF1" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D959BF1" Ref="C6"  Part="1" 
F 0 "C6" H 3715 3396 50  0000 L CNN
F 1 "10uF" H 3715 3305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3638 3200 50  0001 C CNN
F 3 "~" H 3600 3350 50  0001 C CNN
	1    3600 3350
	-1   0    0    1   
$EndComp
$Comp
L ADM8660ARZ-REEL:ADM8660ARZ-REEL U5
U 1 1 5D94F99C
P 4300 3350
F 0 "U5" H 4300 4020 50  0000 C CNN
F 1 "ADM8660ARZ" H 4300 3929 50  0000 C CNN
F 2 "Package_SO:ADM8660ARZ" H 4300 3350 50  0001 L BNN
F 3 "" H 4300 3350 50  0001 L BNN
F 4 "ADM8660ARZ-REEL" H 4300 3350 50  0001 L BNN "Field4"
F 5 "SOIC-8 Analog Devices" H 4300 3350 50  0001 L BNN "Field5"
F 6 "Analog" H 4300 3350 50  0001 L BNN "Field6"
F 7 "None" H 4300 3350 50  0001 L BNN "Field7"
F 8 "Ic Reg Switchd Cap Inv 8soic" H 4300 3350 50  0001 L BNN "Field8"
	1    4300 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	5000 3450 5100 3450
Wire Wire Line
	7050 4500 6950 4500
Wire Wire Line
	6850 3850 6850 4050
Wire Wire Line
	5900 3250 6850 3250
Connection ~ 6850 3250
Wire Wire Line
	6850 3250 6850 3150
$Comp
L Device:C C?
U 1 1 5D95D57E
P 5225 3000
AR Path="/5D95D57E" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D95D57E" Ref="C3"  Part="1" 
F 0 "C3" H 5340 3046 50  0000 L CNN
F 1 "10uF" H 5340 2955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5263 2850 50  0001 C CNN
F 3 "~" H 5225 3000 50  0001 C CNN
	1    5225 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5DAB180C
P 5100 3450
AR Path="/5DAB180C" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5DAB180C" Ref="#PWR0119"  Part="1" 
F 0 "#PWR0119" H 5100 3200 50  0001 C CNN
F 1 "GNDA" H 5105 3277 50  0000 C CNN
F 2 "" H 5100 3450 50  0001 C CNN
F 3 "" H 5100 3450 50  0001 C CNN
	1    5100 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5DADBCA7
P 5100 2600
AR Path="/5DADBCA7" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5DADBCA7" Ref="#PWR0120"  Part="1" 
F 0 "#PWR0120" H 5100 2350 50  0001 C CNN
F 1 "GNDA" H 5105 2427 50  0000 C CNN
F 2 "" H 5100 2600 50  0001 C CNN
F 3 "" H 5100 2600 50  0001 C CNN
	1    5100 2600
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 5150 5150 5350
Wire Wire Line
	5150 5350 4950 5350
$Comp
L power:GNDA #PWR?
U 1 1 5DAF5C09
P 4950 5800
AR Path="/5DAF5C09" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5DAF5C09" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 4950 5550 50  0001 C CNN
F 1 "GNDA" H 4955 5627 50  0000 C CNN
F 2 "" H 4950 5800 50  0001 C CNN
F 3 "" H 4950 5800 50  0001 C CNN
	1    4950 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 5500 4950 5350
Wire Wire Line
	2200 4050 2200 4100
Wire Wire Line
	2200 4100 2800 4100
Wire Wire Line
	3400 4100 3400 4050
Wire Wire Line
	2800 4050 2800 4100
Connection ~ 2800 4100
Wire Wire Line
	2800 4100 3400 4100
Wire Wire Line
	2800 4100 2800 4150
Connection ~ 5150 5350
Wire Wire Line
	5750 3650 5900 3650
Connection ~ 5750 3650
Wire Wire Line
	5750 3650 5750 5350
Wire Wire Line
	5150 4950 5150 4600
Wire Wire Line
	5150 4600 4750 4600
Wire Wire Line
	4750 4550 4750 4600
Connection ~ 4750 4600
Wire Wire Line
	4750 4600 4200 4600
Wire Wire Line
	3400 3650 3600 3650
Connection ~ 3400 3650
Wire Wire Line
	5500 3650 5500 4250
Wire Wire Line
	5500 4250 4050 4250
Connection ~ 5500 3650
Wire Wire Line
	5500 3650 5750 3650
Text HLabel 4050 4250 0    50   Output ~ 0
DVDD3.3V
Text HLabel 1850 3650 0    50   Output ~ 0
AVSS-2.5V
Text HLabel 3650 4950 0    50   Output ~ 0
AVDD2.5V
Text HLabel 8900 3675 0    50   Input ~ 0
DIN
Text HLabel 8900 4375 0    50   Output ~ 0
DOUT
Text HLabel 8900 3475 0    50   Output ~ 0
CLKSEL
Text HLabel 8900 3875 0    50   Output ~ 0
SCLK
Text HLabel 8900 3975 0    50   Output ~ 0
CS
Text HLabel 8900 4275 0    50   Output ~ 0
RESET
Text HLabel 8900 3575 0    50   Input ~ 0
DRDY
Text HLabel 8900 4475 0    50   Input ~ 0
GND
Wire Wire Line
	5000 3650 5500 3650
Wire Wire Line
	5100 3450 5100 3350
Wire Wire Line
	5100 3250 5000 3250
Connection ~ 5100 3450
Wire Wire Line
	5000 3350 5100 3350
Connection ~ 5100 3350
Wire Wire Line
	5100 3350 5100 3250
Wire Wire Line
	5000 3050 5000 3150
Wire Wire Line
	5000 3150 5225 3150
Wire Wire Line
	5000 2950 5000 2850
Wire Wire Line
	5000 2850 5225 2850
Wire Wire Line
	5000 2750 5100 2750
Wire Wire Line
	5100 2750 5100 2600
Text HLabel 8900 4075 0    50   Input ~ 0
START
Text HLabel 8900 3775 0    50   Input ~ 0
DAISY_IN
Text HLabel 8900 4175 0    50   Input ~ 0
CLK
Text HLabel 8900 3375 0    50   Input ~ 0
BIASINV
$Comp
L Connector_Generic:Conn_01x13 J1
U 1 1 66AD6BD8
P 9100 3875
F 0 "J1" H 9180 3917 50  0000 L CNN
F 1 "Conn_01x13" H 9180 3826 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x13_P2.54mm_Vertical" H 9100 3875 50  0001 C CNN
F 3 "~" H 9100 3875 50  0001 C CNN
	1    9100 3875
	1    0    0    -1  
$EndComp
Connection ~ 3600 3650
Wire Wire Line
	6450 4500 6625 4500
$Comp
L power:GNDA #PWR?
U 1 1 5DA73537
P 6625 4950
AR Path="/5DA73537" Ref="#PWR?"  Part="1" 
AR Path="/5D6FC2AC/5DA73537" Ref="#PWR0118"  Part="1" 
F 0 "#PWR0118" H 6625 4700 50  0001 C CNN
F 1 "GNDA" H 6630 4777 50  0000 C CNN
F 2 "" H 6625 4950 50  0001 C CNN
F 3 "" H 6625 4950 50  0001 C CNN
	1    6625 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D938FB9
P 6625 4800
AR Path="/5D938FB9" Ref="C?"  Part="1" 
AR Path="/5D6FC2AC/5D938FB9" Ref="C1"  Part="1" 
F 0 "C1" H 6740 4846 50  0000 L CNN
F 1 "4.7uF" H 6740 4755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6663 4650 50  0001 C CNN
F 3 "~" H 6625 4800 50  0001 C CNN
	1    6625 4800
	-1   0    0    1   
$EndComp
Connection ~ 6625 4500
Wire Wire Line
	6625 4500 6650 4500
Text GLabel 7050 4500 2    50   Input ~ 0
RAW
Text GLabel 8900 3275 0    50   Output ~ 0
RAW
Wire Wire Line
	6450 4500 6450 4050
Wire Wire Line
	6450 4050 6850 4050
Connection ~ 6450 4050
Connection ~ 4950 5350
Wire Wire Line
	4950 5350 4750 5350
Wire Wire Line
	5150 5350 5750 5350
$EndSCHEMATC
