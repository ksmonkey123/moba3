EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
Title "Moba3 - Decoder / Controller"
Date "2021-05-01"
Rev ""
Comp "UART/RS-485 Interface"
Comment1 ""
Comment2 ""
Comment3 "For Controller omit R2."
Comment4 "For Decoder omit U5, R1, R6 and R59."
$EndDescr
Text GLabel 2550 2350 0    50   Input ~ 0
5V
Text GLabel 2500 3450 0    50   Input ~ 0
GND
$Comp
L Interface_UART:MAX481E U4
U 1 1 60EA7BDF
P 3450 2850
F 0 "U4" H 3450 3531 50  0000 C CNN
F 1 "MAX481E" H 3450 3440 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3450 2150 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 3450 2900 50  0001 C CNN
	1    3450 2850
	1    0    0    -1  
$EndComp
Text HLabel 3050 2750 0    50   Input ~ 0
Rx
Wire Wire Line
	3050 2850 2950 2850
Wire Wire Line
	2950 2950 3050 2950
Connection ~ 5250 3050
Wire Wire Line
	5250 3050 5250 2600
$Comp
L Device:R R8
U 1 1 60FD38E0
P 4350 2900
F 0 "R8" H 4420 2946 50  0000 L CNN
F 1 "2k" H 4420 2855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4280 2900 50  0001 C CNN
F 3 "~" H 4350 2900 50  0001 C CNN
	1    4350 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3050 4350 3050
Wire Wire Line
	3850 2750 4350 2750
Connection ~ 4350 2750
Wire Wire Line
	4350 2750 5300 2750
Connection ~ 4350 3050
Wire Wire Line
	4350 3050 5250 3050
Wire Wire Line
	5300 2500 5300 2750
Wire Wire Line
	5250 3050 5250 3950
Wire Wire Line
	5300 3850 5300 2750
Connection ~ 5300 2750
Wire Wire Line
	5300 2500 6000 2500
Wire Wire Line
	5250 2600 6000 2600
Wire Wire Line
	5300 3850 6000 3850
Wire Wire Line
	5250 3950 6000 3950
Wire Wire Line
	6000 4550 6000 4500
Wire Wire Line
	6000 4200 5900 4200
Connection ~ 6000 4200
Text GLabel 5900 4200 0    50   Input ~ 0
GND
Text GLabel 5750 2850 0    50   Input ~ 0
GND
Wire Wire Line
	5750 2850 5900 2850
Connection ~ 6000 2850
Text HLabel 5800 3150 0    50   Input ~ 0
PoE
Wire Wire Line
	6000 3100 6000 3150
Connection ~ 6000 3150
Wire Wire Line
	6000 3150 6000 3200
Text HLabel 5800 4500 0    50   Input ~ 0
PoE
Wire Wire Line
	5800 4500 6000 4500
Connection ~ 6000 4500
Wire Wire Line
	6000 4500 6000 4450
Wire Wire Line
	2950 3050 3050 3050
Wire Wire Line
	2950 2950 2950 3050
Connection ~ 2950 2950
Connection ~ 2950 3450
Wire Wire Line
	2950 3450 3450 3450
Connection ~ 2950 3050
Wire Wire Line
	2950 3050 2950 3450
Wire Wire Line
	2950 2850 2950 2950
Wire Wire Line
	2550 2350 3450 2350
Wire Wire Line
	2500 3450 2950 3450
$Comp
L Connector:RJ45_LED_Shielded J4
U 1 1 60AE9919
P 6400 2800
F 0 "J4" H 6400 3375 50  0000 C CNN
F 1 "RJ45_LED_Shielded" H 6400 3466 50  0000 C CNN
F 2 "customs:RND_RJ45_LED" V 6400 2825 50  0001 C CNN
F 3 "~" V 6400 2825 50  0001 C CNN
	1    6400 2800
	-1   0    0    1   
$EndComp
$Comp
L Connector:RJ45_LED_Shielded J5
U 1 1 60AED713
P 6400 4150
F 0 "J5" H 6400 4725 50  0000 C CNN
F 1 "RJ45_LED_Shielded" H 6400 4816 50  0000 C CNN
F 2 "customs:RND_RJ45_LED" V 6400 4175 50  0001 C CNN
F 3 "~" V 6400 4175 50  0001 C CNN
	1    6400 4150
	-1   0    0    1   
$EndComp
Wire Wire Line
	6000 4200 6000 4250
Wire Wire Line
	6000 2850 6000 2900
Wire Wire Line
	6000 2800 6000 2850
Wire Wire Line
	6000 4150 6000 4200
Text GLabel 6200 3600 0    50   Input ~ 0
GND
Wire Wire Line
	6200 3600 6400 3600
Wire Wire Line
	6400 3600 6400 3650
Text GLabel 6300 2150 0    50   Input ~ 0
GND
Wire Wire Line
	6300 2150 6400 2150
Wire Wire Line
	6400 2150 6400 2300
$Comp
L Device:R R19
U 1 1 60AF997A
P 6950 3100
F 0 "R19" V 6750 3050 50  0000 L CNN
F 1 "1k" V 6850 3050 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6880 3100 50  0001 C CNN
F 3 "~" H 6950 3100 50  0001 C CNN
	1    6950 3100
	0    1    1    0   
$EndComp
Text HLabel 7100 3100 2    50   Input ~ 0
PoE
Text GLabel 6800 3200 2    50   Input ~ 0
GND
$Comp
L Device:R R18
U 1 1 60AFD923
P 6950 2500
F 0 "R18" V 6750 2450 50  0000 L CNN
F 1 "1k" V 6850 2450 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6880 2500 50  0001 C CNN
F 3 "~" H 6950 2500 50  0001 C CNN
	1    6950 2500
	0    1    1    0   
$EndComp
Text HLabel 7100 2500 2    50   Input ~ 0
PoE
Wire Wire Line
	7350 2600 6800 2600
Text HLabel 7500 2750 2    50   Input ~ 0
Rx
Wire Wire Line
	6000 2700 5900 2700
$Comp
L Device:R R21
U 1 1 60B07AA6
P 6800 4750
F 0 "R21" V 6600 4700 50  0000 L CNN
F 1 "1k" V 6700 4700 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6730 4750 50  0001 C CNN
F 3 "~" H 6800 4750 50  0001 C CNN
	1    6800 4750
	-1   0    0    1   
$EndComp
Wire Wire Line
	6800 5000 5550 5000
Wire Wire Line
	6000 4050 5550 4050
Wire Wire Line
	5500 5050 7100 5050
Wire Wire Line
	7100 5050 7100 4450
$Comp
L Device:R R20
U 1 1 60B0B007
P 6950 3850
F 0 "R20" V 6750 3800 50  0000 L CNN
F 1 "1k" V 6850 3800 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6880 3850 50  0001 C CNN
F 3 "~" H 6950 3850 50  0001 C CNN
	1    6950 3850
	0    1    1    0   
$EndComp
Text HLabel 7100 3850 2    50   Input ~ 0
PoE
Wire Wire Line
	6800 3950 7350 3950
Wire Wire Line
	7350 3950 7350 2750
Wire Wire Line
	6800 4900 6800 5000
Wire Wire Line
	6800 4550 6800 4600
Wire Wire Line
	6800 4450 7100 4450
Wire Wire Line
	5500 4350 5500 5050
Wire Wire Line
	5500 4350 6000 4350
Wire Wire Line
	5550 5000 5550 4050
Wire Wire Line
	5800 3150 6000 3150
Wire Wire Line
	5900 2700 5900 2850
Connection ~ 5900 2850
Wire Wire Line
	5900 2850 6000 2850
Wire Wire Line
	6000 3000 6000 3100
Connection ~ 6000 3100
Wire Wire Line
	7500 2750 7350 2750
Connection ~ 7350 2750
Wire Wire Line
	7350 2750 7350 2600
$EndSCHEMATC
