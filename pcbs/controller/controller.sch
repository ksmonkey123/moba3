EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
Title "Moba3 - Decoder / Controller"
Date "2021-05-01"
Rev ""
Comp "Configurable as Controller or Decoder Board"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U1
U 1 1 608DA7CF
P 2000 2900
F 0 "U1" H 2000 1311 50  0000 C CNN
F 1 "ATmega328P-AU" H 2000 1220 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2000 2900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 2000 2900 50  0001 C CNN
	1    2000 2900
	1    0    0    -1  
$EndComp
Text GLabel 2000 1200 1    50   Input ~ 0
5V
Wire Wire Line
	2000 1200 2000 1300
Text GLabel 2000 4650 3    50   Input ~ 0
GND
Wire Wire Line
	2000 4650 2000 4400
Wire Wire Line
	2100 1400 2100 1300
Wire Wire Line
	2100 1300 2000 1300
Connection ~ 2000 1300
Wire Wire Line
	2000 1300 2000 1400
$Comp
L Connector:AVR-ISP-6 J2
U 1 1 608F4114
P 4600 5050
F 0 "J2" H 4271 5146 50  0000 R CNN
F 1 "AVR-ISP-6" H 4271 5055 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" V 4350 5100 50  0001 C CNN
F 3 " ~" H 3325 4500 50  0001 C CNN
	1    4600 5050
	1    0    0    -1  
$EndComp
Text GLabel 4500 4550 1    50   Input ~ 0
5V
Text GLabel 4500 5450 3    50   Input ~ 0
GND
Text GLabel 5000 4850 2    50   Input ~ 0
MISO
Text GLabel 5000 4950 2    50   Input ~ 0
MOSI
Text GLabel 5000 5050 2    50   Input ~ 0
SCK
Text GLabel 5200 5150 2    50   Input ~ 0
~RST
Wire Wire Line
	5200 5150 5000 5150
Text GLabel 3000 3200 2    50   Input ~ 0
~RST
Wire Wire Line
	2600 3200 2800 3200
Text GLabel 2600 2200 2    50   Input ~ 0
SCK
Text GLabel 2600 2000 2    50   Input ~ 0
MOSI
Text GLabel 2600 2100 2    50   Input ~ 0
MISO
$Comp
L Connector:Screw_Terminal_01x03 POWER1
U 1 1 608FC0C4
P 4800 2050
F 0 "POWER1" H 4880 2092 50  0000 L CNN
F 1 "POWER" H 4880 2001 50  0000 L CNN
F 2 "Connector_Wago:Wago_734-133_1x03_P3.50mm_Vertical" H 4800 2050 50  0001 C CNN
F 3 "~" H 4800 2050 50  0001 C CNN
	1    4800 2050
	1    0    0    -1  
$EndComp
Text GLabel 4600 1950 0    50   Input ~ 0
GND
Text GLabel 4600 2050 0    50   Input ~ 0
5V
Text GLabel 2900 1800 2    50   Input ~ 0
~OE
Wire Wire Line
	2900 1800 2600 1800
$Comp
L Device:Crystal Y1
U 1 1 60BEF7B0
P 3200 2350
F 0 "Y1" V 3154 2481 50  0000 L CNN
F 1 "16MHz" V 3245 2481 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 3200 2350 50  0001 C CNN
F 3 "~" H 3200 2350 50  0001 C CNN
	1    3200 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	3200 2200 3000 2200
Wire Wire Line
	3000 2200 3000 2300
Wire Wire Line
	3000 2300 2600 2300
Wire Wire Line
	2600 2400 3000 2400
Wire Wire Line
	3000 2400 3000 2500
Wire Wire Line
	3000 2500 3200 2500
$Comp
L Device:C C1
U 1 1 60C00B84
P 3200 2050
F 0 "C1" H 3085 2004 50  0000 R CNN
F 1 "10pF" H 3085 2095 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3238 1900 50  0001 C CNN
F 3 "~" H 3200 2050 50  0001 C CNN
	1    3200 2050
	-1   0    0    1   
$EndComp
$Comp
L Device:C C2
U 1 1 60C0212D
P 3200 2650
F 0 "C2" H 3085 2604 50  0000 R CNN
F 1 "10pF" H 3085 2695 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3238 2500 50  0001 C CNN
F 3 "~" H 3200 2650 50  0001 C CNN
	1    3200 2650
	-1   0    0    1   
$EndComp
Connection ~ 3200 2500
Connection ~ 3200 2200
Text GLabel 3200 1900 1    50   Input ~ 0
GND
Text GLabel 3200 2800 3    50   Input ~ 0
GND
$Sheet
S 3600 3150 750  600 
U 60ED5CFC
F0 "networking" 50
F1 "networking.sch" 50
F2 "Rx" I L 3600 3400 50 
F3 "PoE" I R 4350 3650 50 
F4 "Tx" I L 3600 3500 50 
$EndSheet
Wire Wire Line
	3600 3400 2600 3400
$Comp
L Device:CP C3
U 1 1 60FB7EA8
P 3850 1400
F 0 "C3" H 3968 1446 50  0000 L CNN
F 1 "220uF" H 3968 1355 50  0000 L CNN
F 2 "Capacitor_THT:C_Radial_D8.0mm_H11.5mm_P3.50mm" H 3888 1250 50  0001 C CNN
F 3 "~" H 3850 1400 50  0001 C CNN
	1    3850 1400
	1    0    0    -1  
$EndComp
Text GLabel 3850 1250 1    50   Input ~ 0
5V
Text GLabel 3850 1550 3    50   Input ~ 0
GND
$Comp
L Device:R R?
U 1 1 60FC8C67
P 2800 3050
AR Path="/60ED5CFC/60FC8C67" Ref="R?"  Part="1" 
AR Path="/60FC8C67" Ref="R1"  Part="1" 
F 0 "R1" H 2870 3096 50  0000 L CNN
F 1 "10k" H 2870 3005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2730 3050 50  0001 C CNN
F 3 "~" H 2800 3050 50  0001 C CNN
	1    2800 3050
	1    0    0    1   
$EndComp
Connection ~ 2800 3200
Wire Wire Line
	2800 3200 3000 3200
Text GLabel 2800 2900 1    50   Input ~ 0
5V
$Comp
L Device:R R?
U 1 1 612E9F9E
P 3300 4450
AR Path="/60ED5CFC/612E9F9E" Ref="R?"  Part="1" 
AR Path="/612E9F9E" Ref="R2"  Part="1" 
F 0 "R2" H 3370 4496 50  0000 L CNN
F 1 "10k" H 3370 4405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3230 4450 50  0001 C CNN
F 3 "~" H 3300 4450 50  0001 C CNN
	1    3300 4450
	1    0    0    1   
$EndComp
$Comp
L Device:LED LED1
U 1 1 612EB260
P 3300 4750
F 0 "LED1" V 3339 4632 50  0000 R CNN
F 1 "LED" V 3248 4632 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 3300 4750 50  0001 C CNN
F 3 "~" H 3300 4750 50  0001 C CNN
	1    3300 4750
	0    -1   -1   0   
$EndComp
Text GLabel 3300 4900 3    50   Input ~ 0
GND
Text GLabel 3300 4300 1    50   Input ~ 0
LED
Text GLabel 3000 3600 2    50   Input ~ 0
LED
Wire Wire Line
	3000 3600 2600 3600
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 609B5F6B
P 2800 5600
F 0 "H1" V 2754 5750 50  0000 L CNN
F 1 "MountingHole_Pad" V 2845 5750 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.5mm_Pad_Via" H 2800 5600 50  0001 C CNN
F 3 "~" H 2800 5600 50  0001 C CNN
	1    2800 5600
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 609B6D2D
P 2800 5800
F 0 "H2" V 2754 5950 50  0000 L CNN
F 1 "MountingHole_Pad" V 2845 5950 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.5mm_Pad_Via" H 2800 5800 50  0001 C CNN
F 3 "~" H 2800 5800 50  0001 C CNN
	1    2800 5800
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 5600 2700 5800
Connection ~ 2700 5800
Wire Wire Line
	2700 5800 2600 5800
Text GLabel 2600 5800 0    50   Input ~ 0
GND
Text GLabel 4600 2150 0    50   Input ~ 0
24V
Text GLabel 4550 3650 2    50   Input ~ 0
5V
Wire Wire Line
	4550 3650 4350 3650
Wire Wire Line
	3600 3500 2600 3500
$EndSCHEMATC