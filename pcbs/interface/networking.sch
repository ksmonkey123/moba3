EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
Title "Moba3 - Decoder / Controller"
Date "2021-05-01"
Rev ""
Comp "UART/RS-485 Interface"
Comment1 ""
Comment2 ""
Comment3 "For Controller omit R2."
Comment4 "For Decoder omit U5, R1, R6 and R59."
$EndDescr
Text GLabel 5750 2850 0    50   Input ~ 0
GND
Wire Wire Line
	5750 2850 6000 2850
Connection ~ 6000 2850
Wire Wire Line
	6000 3100 6000 3150
Connection ~ 6000 3150
Wire Wire Line
	6000 3150 6000 3200
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
Wire Wire Line
	6000 2850 6000 2900
Wire Wire Line
	6000 2800 6000 2850
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
Text HLabel 6800 2600 2    50   Input ~ 0
Tx
Wire Wire Line
	5800 3150 6000 3150
$Comp
L Interface_UART:MAX488E U2
U 1 1 60BEE1EA
P 3750 2700
F 0 "U2" H 3900 3250 50  0000 C CNN
F 1 "MAX488E" H 3950 3150 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 3750 2100 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 3510 3150 50  0001 C CNN
	1    3750 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 2800 4150 2800
Text GLabel 3750 3200 3    50   Input ~ 0
GND
Text GLabel 3750 2200 1    50   Input ~ 0
5V
Text HLabel 3350 2800 0    50   Input ~ 0
Tx
Text HLabel 3350 2600 0    50   Input ~ 0
Rx
$Comp
L Device:R R8
U 1 1 60FD38E0
P 4550 2350
F 0 "R8" H 4620 2396 50  0000 L CNN
F 1 "2k" H 4620 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4480 2350 50  0001 C CNN
F 3 "~" H 4550 2350 50  0001 C CNN
	1    4550 2350
	0    1    -1   0   
$EndComp
Text HLabel 6800 3200 2    50   Input ~ 0
Rx
Wire Wire Line
	4150 2500 4400 2500
Wire Wire Line
	4150 2600 4700 2600
Wire Wire Line
	5300 2800 5300 2700
Wire Wire Line
	5300 2700 6000 2700
Wire Wire Line
	5300 2900 5300 3000
Wire Wire Line
	4150 2900 5300 2900
Wire Wire Line
	5300 3000 6000 3000
Wire Wire Line
	4400 2350 4400 2500
Connection ~ 4400 2500
Wire Wire Line
	4400 2500 6000 2500
Wire Wire Line
	4700 2350 4700 2600
Connection ~ 4700 2600
Wire Wire Line
	4700 2600 6000 2600
Text GLabel 5800 3150 0    50   Input ~ 0
5V
Text GLabel 7100 3100 2    50   Input ~ 0
5V
Text GLabel 7100 2500 2    50   Input ~ 0
5V
$EndSCHEMATC
