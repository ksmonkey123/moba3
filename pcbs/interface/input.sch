EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
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
L 4xxx:4021 U3
U 1 1 60C3957E
P 5500 2250
F 0 "U3" H 5500 3231 50  0000 C CNN
F 1 "4021" H 5500 3140 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 5500 2400 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/HEF4021B.pdf" H 5500 2400 50  0001 C CNN
	1    5500 2250
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4021 U4
U 1 1 60C3B948
P 7050 2250
F 0 "U4" H 7050 3231 50  0000 C CNN
F 1 "4021" H 7050 3140 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 7050 2400 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/HEF4021B.pdf" H 7050 2400 50  0001 C CNN
	1    7050 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J3
U 1 1 60C3F116
P 4400 3500
F 0 "J3" H 4450 4017 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 4450 3926 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 4400 3500 50  0001 C CNN
F 3 "~" H 4400 3500 50  0001 C CNN
	1    4400 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3500 5100 3500
Wire Wire Line
	5100 3500 5100 2850
Wire Wire Line
	3950 2750 3950 3500
Wire Wire Line
	3950 3500 4200 3500
Wire Wire Line
	3950 2750 5100 2750
Wire Wire Line
	4700 3400 5050 3400
Wire Wire Line
	5050 3400 5050 2650
Wire Wire Line
	5050 2650 5100 2650
Wire Wire Line
	4700 3300 5000 3300
Wire Wire Line
	5000 3300 5000 2450
Wire Wire Line
	5000 2450 5100 2450
Wire Wire Line
	5100 2550 3900 2550
Wire Wire Line
	3900 2550 3900 3400
Wire Wire Line
	3900 3400 4200 3400
Wire Wire Line
	4950 3200 4700 3200
Wire Wire Line
	5100 2250 4950 2250
Wire Wire Line
	4950 2250 4950 3200
Wire Wire Line
	5100 2350 3850 2350
Wire Wire Line
	3850 2350 3850 3300
Wire Wire Line
	3850 3300 4200 3300
Wire Wire Line
	4200 3200 3800 3200
Wire Wire Line
	3800 3200 3800 2150
Wire Wire Line
	3800 2150 5100 2150
Wire Wire Line
	6650 2150 6000 2150
Wire Wire Line
	6000 2150 6000 4000
Wire Wire Line
	6000 4000 3950 4000
Wire Wire Line
	3950 4000 3950 3600
Wire Wire Line
	3950 3600 4200 3600
Wire Wire Line
	6650 2350 6100 2350
Wire Wire Line
	6100 2350 6100 4050
Wire Wire Line
	6100 4050 4000 4050
Wire Wire Line
	4000 4050 4000 3700
Wire Wire Line
	4000 3700 4200 3700
Wire Wire Line
	6650 2550 6200 2550
Wire Wire Line
	6200 2550 6200 4100
Wire Wire Line
	6200 4100 4050 4100
Wire Wire Line
	4050 4100 4050 3800
Wire Wire Line
	4050 3800 4200 3800
Wire Wire Line
	6650 2750 6300 2750
Wire Wire Line
	6300 2750 6300 4150
Wire Wire Line
	6300 4150 4100 4150
Wire Wire Line
	4100 4150 4100 3900
Wire Wire Line
	4100 3900 4200 3900
Wire Wire Line
	6650 2250 6050 2250
Wire Wire Line
	6050 2250 6050 3600
Wire Wire Line
	6650 2450 6150 2450
Wire Wire Line
	6650 2650 6250 2650
Wire Wire Line
	6250 2650 6250 3800
Wire Wire Line
	6350 3900 6350 2850
Wire Wire Line
	6350 2850 6650 2850
Wire Wire Line
	5900 1850 6050 1850
Wire Wire Line
	6050 1850 6050 1950
Wire Wire Line
	6050 1950 6650 1950
Text HLabel 7450 1850 2    50   Input ~ 0
Serial_Out
Text GLabel 5500 3050 3    50   Input ~ 0
GND
Text GLabel 7050 3050 3    50   Input ~ 0
GND
Wire Wire Line
	6150 2450 6150 3700
Wire Wire Line
	6050 3600 4700 3600
Wire Wire Line
	6150 3700 4700 3700
Wire Wire Line
	6250 3800 4700 3800
Wire Wire Line
	4700 3900 6350 3900
Text HLabel 6650 1850 0    50   Input ~ 0
Load
Text HLabel 5100 1650 0    50   Input ~ 0
Clock
Text HLabel 5100 1850 0    50   Input ~ 0
Load
Text HLabel 6650 1650 0    50   Input ~ 0
Clock
Text GLabel 5250 1450 0    50   Input ~ 0
5V
Wire Wire Line
	5250 1450 5500 1450
Connection ~ 5500 1450
Wire Wire Line
	5500 1450 7050 1450
$EndSCHEMATC
