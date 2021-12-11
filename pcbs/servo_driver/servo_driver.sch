EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Connector:AVR-ISP-6 J1
U 1 1 608F4114
P 4600 5050
F 0 "J1" H 4271 5146 50  0000 R CNN
F 1 "AVR-ISP-6" H 4271 5055 50  0000 R CNN
F 2 "Connector_IDC:IDC-Header_2x03_P2.54mm_Vertical" V 4350 5100 50  0001 C CNN
F 3 " ~" H 3325 4500 50  0001 C CNN
	1    4600 5050
	1    0    0    -1  
$EndComp
Text GLabel 5000 4850 2    50   Input ~ 0
5V
Text GLabel 5200 5150 2    50   Input ~ 0
GND
Text GLabel 4500 4550 2    50   Input ~ 0
MISO
Text GLabel 5000 5050 2    50   Input ~ 0
MOSI
Text GLabel 5000 4950 2    50   Input ~ 0
SCK
Text GLabel 4500 5450 2    50   Input ~ 0
~RST
Wire Wire Line
	5200 5150 5000 5150
Text GLabel 3000 3200 2    50   Input ~ 0
~RST
Text GLabel 2600 2200 2    50   Input ~ 0
SCK
Text GLabel 2600 2000 2    50   Input ~ 0
MOSI
Text GLabel 2600 2100 2    50   Input ~ 0
MISO
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
$Comp
L Device:CP C4
U 1 1 60FB7EA8
P 3850 1400
F 0 "C4" H 3968 1446 50  0000 L CNN
F 1 "220uF" H 3968 1355 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_6.3x7.7" H 3888 1250 50  0001 C CNN
F 3 "~" H 3850 1400 50  0001 C CNN
	1    3850 1400
	1    0    0    -1  
$EndComp
Text GLabel 3650 1150 1    50   Input ~ 0
5V
Text GLabel 3650 1650 3    50   Input ~ 0
GND
$Comp
L Device:R R?
U 1 1 60FC8C67
P 2900 3050
AR Path="/60ED5CFC/60FC8C67" Ref="R?"  Part="1" 
AR Path="/60FC8C67" Ref="R3"  Part="1" 
F 0 "R3" H 2970 3096 50  0000 L CNN
F 1 "10k" H 2970 3005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2830 3050 50  0001 C CNN
F 3 "~" H 2900 3050 50  0001 C CNN
	1    2900 3050
	1    0    0    1   
$EndComp
Text GLabel 2900 2900 1    50   Input ~ 0
5V
$Comp
L Device:C C3
U 1 1 61B21DEA
P 3400 1400
F 0 "C3" H 3285 1354 50  0000 R CNN
F 1 "100nF" H 3285 1445 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3438 1250 50  0001 C CNN
F 3 "~" H 3400 1400 50  0001 C CNN
	1    3400 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	3400 1550 3650 1550
Wire Wire Line
	3400 1250 3650 1250
Wire Wire Line
	3650 1150 3650 1250
Connection ~ 3650 1250
Wire Wire Line
	3650 1250 3850 1250
Wire Wire Line
	3650 1550 3650 1650
Connection ~ 3650 1550
Wire Wire Line
	3650 1550 3850 1550
$Comp
L Device:R_POT_TRIM RV1
U 1 1 61B26AB0
P 4100 2850
F 0 "RV1" H 4030 2896 50  0000 R CNN
F 1 "47k" H 4030 2805 50  0000 R CNN
F 2 "Potentiometer_SMD:Potentiometer_Bourns_3314J_Vertical" H 4100 2850 50  0001 C CNN
F 3 "~" H 4100 2850 50  0001 C CNN
	1    4100 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM RV2
U 1 1 61B2855A
P 4700 2850
F 0 "RV2" H 4630 2896 50  0000 R CNN
F 1 "47k" H 4630 2805 50  0000 R CNN
F 2 "Potentiometer_SMD:Potentiometer_Bourns_3314J_Vertical" H 4700 2850 50  0001 C CNN
F 3 "~" H 4700 2850 50  0001 C CNN
	1    4700 2850
	1    0    0    -1  
$EndComp
Text GLabel 4100 3000 3    50   Input ~ 0
GND
Text GLabel 4700 3000 3    50   Input ~ 0
GND
Text GLabel 4100 2700 1    50   Input ~ 0
5V
Text GLabel 4700 2700 1    50   Input ~ 0
5V
Text GLabel 2600 3400 2    50   Input ~ 0
LED_A
$Comp
L Device:R R?
U 1 1 61B2F99B
P 4100 3650
AR Path="/60ED5CFC/61B2F99B" Ref="R?"  Part="1" 
AR Path="/61B2F99B" Ref="R1"  Part="1" 
F 0 "R1" H 4170 3696 50  0000 L CNN
F 1 "10k" H 4170 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4030 3650 50  0001 C CNN
F 3 "~" H 4100 3650 50  0001 C CNN
	1    4100 3650
	1    0    0    1   
$EndComp
$Comp
L Device:LED LED1
U 1 1 61B2F9A1
P 4100 3950
F 0 "LED1" V 4139 3832 50  0000 R CNN
F 1 "LED" V 4048 3832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 4100 3950 50  0001 C CNN
F 3 "~" H 4100 3950 50  0001 C CNN
	1    4100 3950
	0    -1   -1   0   
$EndComp
Text GLabel 4100 4100 3    50   Input ~ 0
GND
$Comp
L Device:R R?
U 1 1 61B324E9
P 4700 3650
AR Path="/60ED5CFC/61B324E9" Ref="R?"  Part="1" 
AR Path="/61B324E9" Ref="R2"  Part="1" 
F 0 "R2" H 4770 3696 50  0000 L CNN
F 1 "10k" H 4770 3605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4630 3650 50  0001 C CNN
F 3 "~" H 4700 3650 50  0001 C CNN
	1    4700 3650
	1    0    0    1   
$EndComp
$Comp
L Device:LED LED2
U 1 1 61B324EF
P 4700 3950
F 0 "LED2" V 4739 3832 50  0000 R CNN
F 1 "LED" V 4648 3832 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 4700 3950 50  0001 C CNN
F 3 "~" H 4700 3950 50  0001 C CNN
	1    4700 3950
	0    -1   -1   0   
$EndComp
Text GLabel 4700 4100 3    50   Input ~ 0
GND
Text GLabel 4100 3500 1    50   Input ~ 0
LED_A
Text GLabel 4700 3500 1    50   Input ~ 0
LED_B
Text GLabel 2600 2700 2    50   Input ~ 0
LED_B
$Comp
L Connector:Screw_Terminal_01x04 J2
U 1 1 61B39B40
P 5800 1800
F 0 "J2" H 5880 1792 50  0000 L CNN
F 1 "Screw_Terminal_01x04" H 5880 1701 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_MPT-0,5-4-2.54_1x04_P2.54mm_Horizontal" H 5800 1800 50  0001 C CNN
F 3 "~" H 5800 1800 50  0001 C CNN
	1    5800 1800
	1    0    0    -1  
$EndComp
Text GLabel 5600 1800 0    50   Input ~ 0
5V
Text GLabel 5600 1700 0    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 61B3E821
P 5850 2450
F 0 "J3" H 5822 2424 50  0000 R CNN
F 1 "Conn_01x04_Male" H 5822 2333 50  0000 R CNN
F 2 "Connector_JST:JST_PH_B4B-PH-K_1x04_P2.00mm_Vertical" H 5850 2450 50  0001 C CNN
F 3 "~" H 5850 2450 50  0001 C CNN
	1    5850 2450
	-1   0    0    -1  
$EndComp
Text GLabel 5650 2350 0    50   Input ~ 0
GND
Text GLabel 5650 2450 0    50   Input ~ 0
5V
Text GLabel 2600 2900 2    50   Input ~ 0
servo
Text GLabel 5650 2650 0    50   Input ~ 0
servo
Text GLabel 5600 1900 0    50   Input ~ 0
sig_A
Text GLabel 5600 2000 0    50   Input ~ 0
sig_B
Text GLabel 2600 1700 2    50   Input ~ 0
sig_A
Text GLabel 2600 1800 2    50   Input ~ 0
sig_B
Text GLabel 4450 1600 1    50   Input ~ 0
sig_A
Text GLabel 4750 1600 1    50   Input ~ 0
sig_B
$Comp
L Device:C C5
U 1 1 61B4AEDB
P 4450 1750
F 0 "C5" H 4335 1704 50  0000 R CNN
F 1 "100nF" H 4335 1795 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4488 1600 50  0001 C CNN
F 3 "~" H 4450 1750 50  0001 C CNN
	1    4450 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 61B4BA34
P 4750 1750
F 0 "C6" H 4635 1704 50  0000 R CNN
F 1 "100nF" H 4635 1795 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4788 1600 50  0001 C CNN
F 3 "~" H 4750 1750 50  0001 C CNN
	1    4750 1750
	-1   0    0    -1  
$EndComp
Text GLabel 4600 2050 3    50   Input ~ 0
GND
Wire Wire Line
	4450 1900 4600 1900
Wire Wire Line
	4600 1900 4600 2050
Wire Wire Line
	4750 1900 4600 1900
Connection ~ 4600 1900
Text GLabel 4250 2850 2    50   Input ~ 0
rv1
Text GLabel 2600 3100 2    50   Input ~ 0
rv1
Text GLabel 2600 2800 2    50   Input ~ 0
rv2
Text GLabel 4850 2850 2    50   Input ~ 0
rv2
$Comp
L Switch:SW_Push SW1
U 1 1 61B52358
P 3400 3650
F 0 "SW1" V 3354 3798 50  0000 L CNN
F 1 "SW_Push" V 3445 3798 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H7.3mm" H 3400 3850 50  0001 C CNN
F 3 "~" H 3400 3850 50  0001 C CNN
	1    3400 3650
	0    1    1    0   
$EndComp
Text GLabel 3400 3850 3    50   Input ~ 0
GND
Text GLabel 3400 3450 1    50   Input ~ 0
sig_T
Text GLabel 2600 3000 2    50   Input ~ 0
sig_T
Text Label 3000 2250 1    50   ~ 0
XTAL1
Text Label 2950 2400 3    50   ~ 0
XTAL2
Connection ~ 2900 3200
Wire Wire Line
	2900 3200 3000 3200
Wire Wire Line
	2600 3200 2900 3200
$Comp
L Device:C C7
U 1 1 61BAABF2
P 5500 3450
F 0 "C7" H 5385 3404 50  0000 R CNN
F 1 "100nF" H 5385 3495 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5538 3300 50  0001 C CNN
F 3 "~" H 5500 3450 50  0001 C CNN
	1    5500 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 61BAC576
P 6000 3450
F 0 "C8" H 5885 3404 50  0000 R CNN
F 1 "100nF" H 5885 3495 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6038 3300 50  0001 C CNN
F 3 "~" H 6000 3450 50  0001 C CNN
	1    6000 3450
	1    0    0    -1  
$EndComp
Text GLabel 5500 3300 1    50   Input ~ 0
rv1
Text GLabel 6000 3300 1    50   Input ~ 0
rv2
Text GLabel 5500 3600 3    50   Input ~ 0
GND
Text GLabel 6000 3600 3    50   Input ~ 0
GND
$Comp
L Device:R R?
U 1 1 61BB6636
P 3050 4850
AR Path="/60ED5CFC/61BB6636" Ref="R?"  Part="1" 
AR Path="/61BB6636" Ref="R4"  Part="1" 
F 0 "R4" H 3120 4896 50  0000 L CNN
F 1 "10k" H 3120 4805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 4850 50  0001 C CNN
F 3 "~" H 3050 4850 50  0001 C CNN
	1    3050 4850
	1    0    0    1   
$EndComp
$Comp
L Device:LED LED3
U 1 1 61BB663C
P 3050 5150
F 0 "LED3" V 3089 5032 50  0000 R CNN
F 1 "LED" V 2998 5032 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 3050 5150 50  0001 C CNN
F 3 "~" H 3050 5150 50  0001 C CNN
	1    3050 5150
	0    -1   -1   0   
$EndComp
Text GLabel 3050 5300 3    50   Input ~ 0
GND
Text GLabel 3050 4700 1    50   Input ~ 0
LED_C
Text GLabel 2600 1900 2    50   Input ~ 0
LED_C
$EndSCHEMATC
