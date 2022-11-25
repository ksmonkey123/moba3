EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "Moba3 - Controller"
Date "2021-05-01"
Rev ""
Comp "UART/RS-485 Interface"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "For Decoder omit U5, R1, R6 and R59."
$EndDescr
Text GLabel 4350 2550 1    50   Input ~ 0
5V
$Comp
L Interface_UART:MAX481E U2
U 1 1 60EA7BDF
P 4350 3100
F 0 "U2" H 4500 3700 50  0000 C CNN
F 1 "MAX481E" H 4550 3600 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4350 2400 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 4350 3150 50  0001 C CNN
	1    4350 3100
	1    0    0    -1  
$EndComp
Text HLabel 3950 3300 0    50   Input ~ 0
Tx
Wire Wire Line
	5250 3300 5250 3950
Wire Wire Line
	5300 3850 5300 3000
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
	5750 2850 6000 2850
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
$Comp
L Connector:RJ45_LED_Shielded J1
U 1 1 60AE9919
P 6400 2800
F 0 "J1" H 6400 3375 50  0000 C CNN
F 1 "RJ45_LED_Shielded" H 6400 3466 50  0000 C CNN
F 2 "customs:RND_RJ45_LED" V 6400 2825 50  0001 C CNN
F 3 "~" V 6400 2825 50  0001 C CNN
	1    6400 2800
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
L Device:R R8
U 1 1 60AF997A
P 6950 3100
F 0 "R8" V 6750 3050 50  0000 L CNN
F 1 "1k" V 6850 3050 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6880 3100 50  0001 C CNN
F 3 "~" H 6950 3100 50  0001 C CNN
	1    6950 3100
	0    1    1    0   
$EndComp
Text HLabel 7100 3100 2    50   Input ~ 0
PoE
$Comp
L Device:R R7
U 1 1 60AFD923
P 6950 2500
F 0 "R7" V 6750 2450 50  0000 L CNN
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
$Comp
L Device:R R6
U 1 1 60B07AA6
P 6800 4750
F 0 "R6" V 6600 4700 50  0000 L CNN
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
L Device:R R9
U 1 1 60B0B007
P 6950 3850
F 0 "R9" V 6750 3800 50  0000 L CNN
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
	5800 3150 6000 3150
Wire Wire Line
	5400 3000 6000 3000
Wire Wire Line
	5300 2500 6000 2500
Wire Wire Line
	5300 1600 4700 1600
Wire Wire Line
	5300 1600 5300 2500
Wire Wire Line
	4700 1700 5250 1700
Wire Wire Line
	5250 1700 5250 2600
Wire Wire Line
	6000 2700 5350 2700
Wire Wire Line
	5350 2700 5350 1800
Wire Wire Line
	5350 1500 4700 1500
Wire Wire Line
	4700 1400 5400 1400
Wire Wire Line
	5400 1400 5400 1500
Text GLabel 4350 2150 3    50   Input ~ 0
GND
Text HLabel 3900 1700 0    50   Input ~ 0
Tx
Text HLabel 3900 1400 0    50   Input ~ 0
Rx
$Comp
L Device:R R5
U 1 1 60FD38E0
P 5550 1650
F 0 "R5" H 5620 1696 50  0000 L CNN
F 1 "2k" H 5620 1605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5480 1650 50  0001 C CNN
F 3 "~" H 5550 1650 50  0001 C CNN
	1    5550 1650
	1    0    0    1   
$EndComp
Wire Wire Line
	4750 3300 5250 3300
Wire Wire Line
	4750 3000 5300 3000
Wire Wire Line
	5550 1500 5400 1500
Connection ~ 5400 1500
Wire Wire Line
	5400 1500 5400 3000
Wire Wire Line
	5550 1800 5350 1800
Connection ~ 5350 1800
Wire Wire Line
	5350 1800 5350 1500
Wire Wire Line
	5500 4350 5500 5050
Wire Wire Line
	5500 4350 6000 4350
Wire Wire Line
	5550 5000 5550 4050
$Comp
L Connector:RJ45_LED_Shielded J2
U 1 1 60AED713
P 6400 4150
F 0 "J2" H 6400 4725 50  0000 C CNN
F 1 "RJ45_LED_Shielded" H 6400 4816 50  0000 C CNN
F 2 "customs:RND_RJ45_LED" V 6400 4175 50  0001 C CNN
F 3 "~" V 6400 4175 50  0001 C CNN
	1    6400 4150
	-1   0    0    1   
$EndComp
Wire Wire Line
	6800 5000 6800 4900
Wire Wire Line
	6800 4550 6800 4600
Wire Wire Line
	6800 4450 7100 4450
Text HLabel 6800 3200 2    50   Input ~ 0
Rx
Wire Wire Line
	7350 3950 7350 2850
Wire Wire Line
	7450 2850 7350 2850
Connection ~ 7350 2850
Wire Wire Line
	7350 2850 7350 2600
Text HLabel 7450 2850 2    50   Input ~ 0
Tx
$Comp
L Interface_UART:MAX489E U1
U 1 1 637A95E3
P 4300 1500
F 0 "U1" H 4500 2050 50  0000 C CNN
F 1 "MAX489E" H 4500 1950 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 4300 800 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 4350 1525 50  0001 C CNN
	1    4300 1500
	1    0    0    -1  
$EndComp
Text GLabel 4350 3850 3    50   Input ~ 0
GND
Wire Wire Line
	4350 3850 4350 3700
Wire Wire Line
	4350 2550 4350 2600
Wire Wire Line
	4350 2600 3850 2600
Wire Wire Line
	3850 3100 3950 3100
Connection ~ 4350 2600
Text GLabel 4300 900  1    50   Input ~ 0
5V
Wire Wire Line
	3850 2600 3850 3100
$Comp
L Transistor_FET:2N7002 Q1
U 1 1 63801EE5
P 2100 2950
F 0 "Q1" H 2304 2996 50  0000 L CNN
F 1 "2N7002" H 2304 2905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2300 2875 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 2100 2950 50  0001 L CNN
	1    2100 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 638292A4
P 1750 2950
F 0 "R2" V 1550 2900 50  0000 L CNN
F 1 "10k" V 1650 2900 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1680 2950 50  0001 C CNN
F 3 "~" H 1750 2950 50  0001 C CNN
	1    1750 2950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 63831E1E
P 2300 1250
F 0 "R4" V 2100 1200 50  0000 L CNN
F 1 "10k" V 2200 1200 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2230 1250 50  0001 C CNN
F 3 "~" H 2300 1250 50  0001 C CNN
	1    2300 1250
	1    0    0    -1  
$EndComp
Text GLabel 2300 1100 1    50   Input ~ 0
5V
Wire Wire Line
	4300 900  4300 1000
$Comp
L Device:R R3
U 1 1 63844CF9
P 2200 2600
F 0 "R3" V 2000 2550 50  0000 L CNN
F 1 "10k" V 2100 2550 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2130 2600 50  0001 C CNN
F 3 "~" H 2200 2600 50  0001 C CNN
	1    2200 2600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 638455B8
P 1400 3100
F 0 "R1" V 1200 3050 50  0000 L CNN
F 1 "10k" V 1300 3050 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1330 3100 50  0001 C CNN
F 3 "~" H 1400 3100 50  0001 C CNN
	1    1400 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	1400 2950 1600 2950
Wire Wire Line
	1400 3250 2200 3250
Wire Wire Line
	2200 3250 2200 3150
Text GLabel 2200 2450 1    50   Input ~ 0
5V
Text GLabel 2200 3350 3    50   Input ~ 0
GND
Wire Wire Line
	2200 3250 2200 3350
Connection ~ 2200 3250
Text HLabel 3600 3200 0    50   Input ~ 0
net_en
Wire Wire Line
	1200 2950 1400 2950
Connection ~ 1400 2950
Wire Wire Line
	4300 2100 4350 2100
Wire Wire Line
	4350 2100 4350 2150
Connection ~ 4350 2100
Wire Wire Line
	4350 2100 4400 2100
Text Label 3550 1500 2    50   ~ 0
~rx_en
Wire Wire Line
	3550 1500 3900 1500
Wire Wire Line
	3900 1600 3700 1600
Wire Wire Line
	2500 2750 2200 2750
Connection ~ 2200 2750
Text Label 2500 2750 0    50   ~ 0
~rx_en
Wire Wire Line
	3950 3200 3700 3200
Wire Wire Line
	3700 3200 3700 1600
Wire Wire Line
	3600 3200 3700 3200
Connection ~ 3700 3200
Text Label 2300 1700 3    50   ~ 0
~rx_en
Text HLabel 1200 2950 0    50   Input ~ 0
net_en
$Comp
L Device:LED D1
U 1 1 63836B2D
P 2300 1550
F 0 "D1" V 2339 1432 50  0000 R CNN
F 1 "LED" V 2248 1432 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 2300 1550 50  0001 C CNN
F 3 "~" H 2300 1550 50  0001 C CNN
	1    2300 1550
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
