EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "lun. 30 mars 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 8950 1450 1    60   ~ 0
Vin
Text Label 9350 1450 1    60   ~ 0
IOREF
Text Label 8900 2500 0    60   ~ 0
A0
Text Label 8900 2600 0    60   ~ 0
A1
Text Label 8900 2700 0    60   ~ 0
A2
Text Label 8900 2800 0    60   ~ 0
A3
Text Label 8900 2900 0    60   ~ 0
A4(SDA)
Text Label 8900 3000 0    60   ~ 0
A5(SCL)
Text Label 10550 3000 0    60   ~ 0
0(Rx)
Text Label 10550 2800 0    60   ~ 0
2
Text Label 10550 2900 0    60   ~ 0
1(Tx)
Text Label 10550 2700 0    60   ~ 0
3(**)
Text Label 10550 2600 0    60   ~ 0
4
Text Label 10550 2500 0    60   ~ 0
5(**)
Text Label 10550 2400 0    60   ~ 0
6(**)
Text Label 10550 2300 0    60   ~ 0
7
Text Label 10550 2100 0    60   ~ 0
8
Text Label 10550 2000 0    60   ~ 0
9(**)
Text Label 10550 1900 0    60   ~ 0
10(**/SS)
Text Label 10550 1800 0    60   ~ 0
11(**/MOSI)
Text Label 10550 1700 0    60   ~ 0
12(MISO)
Text Label 10550 1600 0    60   ~ 0
13(SCK)
Text Label 10550 1400 0    60   ~ 0
AREF
NoConn ~ 9400 1600
Text Label 10550 1300 0    60   ~ 0
A4(SDA)
Text Label 10550 1200 0    60   ~ 0
A5(SCL)
Text Notes 10850 1000 0    60   ~ 0
Holes
Text Notes 8550 750  0    60   ~ 0
Shield for Arduino that uses\nthe same pin disposition\nlike "Uno" board Rev 3.
$Comp
L Connector_Generic:Conn_01x08 P1
U 1 1 56D70129
P 9600 1900
F 0 "P1" H 9600 2350 50  0000 C CNN
F 1 "Power" V 9700 1900 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 9750 1900 20  0000 C CNN
F 3 "" H 9600 1900 50  0000 C CNN
	1    9600 1900
	1    0    0    -1  
$EndComp
Text Label 8650 1800 0    60   ~ 0
Reset
$Comp
L power:+3.3V #PWR01
U 1 1 56D70538
P 9150 1450
F 0 "#PWR01" H 9150 1300 50  0001 C CNN
F 1 "+3.3V" V 9150 1700 50  0000 C CNN
F 2 "" H 9150 1450 50  0000 C CNN
F 3 "" H 9150 1450 50  0000 C CNN
	1    9150 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 56D707BB
P 9050 1350
F 0 "#PWR02" H 9050 1200 50  0001 C CNN
F 1 "+5V" V 9050 1550 50  0000 C CNN
F 2 "" H 9050 1350 50  0000 C CNN
F 3 "" H 9050 1350 50  0000 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 56D70CC2
P 9300 3150
F 0 "#PWR03" H 9300 2900 50  0001 C CNN
F 1 "GND" H 9300 3000 50  0000 C CNN
F 2 "" H 9300 3150 50  0000 C CNN
F 3 "" H 9300 3150 50  0000 C CNN
	1    9300 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 56D70CFF
P 10300 3150
F 0 "#PWR04" H 10300 2900 50  0001 C CNN
F 1 "GND" H 10300 3000 50  0000 C CNN
F 2 "" H 10300 3150 50  0000 C CNN
F 3 "" H 10300 3150 50  0000 C CNN
	1    10300 3150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 P2
U 1 1 56D70DD8
P 9600 2700
F 0 "P2" H 9600 2300 50  0000 C CNN
F 1 "Analog" V 9700 2700 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x06" V 9750 2750 20  0000 C CNN
F 3 "" H 9600 2700 50  0000 C CNN
	1    9600 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 P4
U 1 1 56D7164F
P 10000 2600
F 0 "P4" H 10000 2100 50  0000 C CNN
F 1 "Digital" V 10100 2600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 10150 2550 20  0000 C CNN
F 3 "" H 10000 2600 50  0000 C CNN
	1    10000 2600
	-1   0    0    -1  
$EndComp
Wire Notes Line
	8525 825  9925 825 
Wire Notes Line
	9925 825  9925 475 
Wire Wire Line
	9350 1450 9350 1700
Wire Wire Line
	9350 1700 9400 1700
Wire Wire Line
	9400 1900 9150 1900
Wire Wire Line
	9400 2000 9050 2000
Wire Wire Line
	9400 2300 8950 2300
Wire Wire Line
	9400 2100 9300 2100
Wire Wire Line
	9400 2200 9300 2200
Connection ~ 9300 2200
Wire Wire Line
	8950 2300 8950 1450
Wire Wire Line
	9050 2000 9050 1350
Wire Wire Line
	9150 1900 9150 1450
Wire Wire Line
	9400 2500 8900 2500
Wire Wire Line
	9400 2600 8900 2600
Wire Wire Line
	9400 2700 8900 2700
Wire Wire Line
	9400 2800 8900 2800
Wire Wire Line
	9400 2900 8900 2900
Wire Wire Line
	9400 3000 8900 3000
$Comp
L Connector_Generic:Conn_01x10 P3
U 1 1 56D721E0
P 10000 1600
F 0 "P3" H 10000 2150 50  0000 C CNN
F 1 "Digital" V 10100 1600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x10" V 10150 1600 20  0000 C CNN
F 3 "" H 10000 1600 50  0000 C CNN
	1    10000 1600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10200 2100 10550 2100
Wire Wire Line
	10200 2000 10550 2000
Wire Wire Line
	10200 1900 10550 1900
Wire Wire Line
	10200 1800 10550 1800
Wire Wire Line
	10200 1700 10550 1700
Wire Wire Line
	10200 1600 10550 1600
Wire Wire Line
	10200 1400 10550 1400
Wire Wire Line
	10200 1300 10550 1300
Wire Wire Line
	10200 1200 10550 1200
Wire Wire Line
	10200 3000 10550 3000
Wire Wire Line
	10200 2900 10550 2900
Wire Wire Line
	10200 2800 10550 2800
Wire Wire Line
	10200 2700 10550 2700
Wire Wire Line
	10200 2600 10550 2600
Wire Wire Line
	10200 2500 10550 2500
Wire Wire Line
	10200 2400 10550 2400
Wire Wire Line
	10200 2300 10550 2300
Wire Wire Line
	10200 1500 10300 1500
Wire Wire Line
	10300 1500 10300 3150
Wire Wire Line
	9300 2100 9300 2200
Wire Wire Line
	9300 2200 9300 3150
Wire Notes Line
	8500 500  8500 3450
Wire Notes Line
	8500 3450 11200 3450
Text Notes 9700 1600 0    60   ~ 0
1
Wire Notes Line
	11200 1000 10700 1000
Wire Notes Line
	10700 1000 10700 500 
Wire Wire Line
	6050 1800 6650 1800
Wire Wire Line
	6650 1900 6100 1900
Wire Wire Line
	5500 2900 6150 2900
Wire Wire Line
	6150 2900 6150 2000
Wire Wire Line
	6150 2000 6650 2000
Wire Wire Line
	6650 2300 6200 2300
Wire Wire Line
	6200 2300 6200 3000
Wire Wire Line
	6200 3000 5500 3000
Wire Wire Line
	6150 2900 6150 3250
Wire Wire Line
	6150 3250 6650 3250
Connection ~ 6150 2900
Wire Wire Line
	6650 3350 6200 3350
Wire Wire Line
	6200 3350 6200 3000
Connection ~ 6200 3000
Wire Wire Line
	6650 3450 6050 3450
Wire Wire Line
	6100 3750 6650 3750
Wire Wire Line
	6650 2100 6400 2100
Wire Wire Line
	6400 2100 6400 2150
Wire Wire Line
	6400 3550 6650 3550
Wire Wire Line
	6650 3850 6500 3850
Wire Wire Line
	6500 3850 6500 2400
Wire Wire Line
	6500 2400 6650 2400
Text GLabel 5800 2150 0    50   Input ~ 0
GND
Connection ~ 6400 2150
Wire Wire Line
	6400 2150 6400 3550
Text GLabel 5650 2400 0    50   Input ~ 0
5V
Wire Wire Line
	5950 2400 6500 2400
Connection ~ 6500 2400
$Comp
L power:+5V #PWR06
U 1 1 60C42863
P 4550 2300
F 0 "#PWR06" H 4550 2150 50  0001 C CNN
F 1 "+5V" V 4550 2500 50  0000 C CNN
F 2 "" H 4550 2300 50  0000 C CNN
F 3 "" H 4550 2300 50  0000 C CNN
	1    4550 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 60C47A29
P 5950 2150
F 0 "#PWR05" H 5950 1900 50  0001 C CNN
F 1 "GND" H 5950 2000 50  0000 C CNN
F 2 "" H 5950 2150 50  0000 C CNN
F 3 "" H 5950 2150 50  0000 C CNN
	1    5950 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2150 6400 2150
Wire Wire Line
	5800 2150 5950 2150
Connection ~ 5950 2150
Text GLabel 5150 3500 3    50   Input ~ 0
GND
Text Label 4100 2700 0    60   ~ 0
1(Tx)
Text Label 4150 3000 0    60   ~ 0
0(Rx)
$Comp
L Interface_UART:MAX489E U1
U 1 1 60C582EB
P 5100 2800
F 0 "U1" H 5100 3481 50  0000 C CNN
F 1 "MAX489E" H 5100 3390 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 5100 2100 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX1487E-MAX491E.pdf" H 5150 2825 50  0001 C CNN
	1    5100 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1800 6050 2800
Wire Wire Line
	5500 2800 6050 2800
Connection ~ 6050 2800
Wire Wire Line
	6050 2800 6050 3450
Wire Wire Line
	5500 2700 6100 2700
Connection ~ 6100 2700
Wire Wire Line
	6100 2700 6100 3750
Wire Wire Line
	6100 1900 6100 2700
Wire Wire Line
	5150 3500 5150 3450
Wire Wire Line
	5150 3450 5100 3450
Wire Wire Line
	5100 3450 5100 3400
Wire Wire Line
	5150 3450 5200 3450
Wire Wire Line
	5200 3450 5200 3400
Connection ~ 5150 3450
Text GLabel 4400 2300 0    50   Input ~ 0
5V
Wire Wire Line
	4700 2900 4550 2900
Wire Wire Line
	4550 2900 4550 2450
Wire Wire Line
	4550 2300 5100 2300
Wire Wire Line
	4400 2300 4550 2300
Connection ~ 4550 2300
Wire Wire Line
	4700 3000 4150 3000
Wire Wire Line
	4700 2700 4100 2700
$Comp
L custom:CNY74-2H OC1
U 2 1 60C77AEA
P 5150 1750
F 0 "OC1" H 5100 2075 50  0000 C CNN
F 1 "CNY74-2H" H 5100 1984 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_LongPads" H 5150 1750 50  0001 C CNN
F 3 "https://www.vishay.com/docs/83526/83526.pdf" H 5150 1750 50  0001 C CNN
	2    5150 1750
	1    0    0    -1  
$EndComp
$Comp
L custom:CNY74-2H OC1
U 1 1 60C79469
P 3700 3250
F 0 "OC1" H 3650 3575 50  0000 C CNN
F 1 "CNY74-2H" H 3650 3484 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_LongPads" H 3700 3250 50  0001 C CNN
F 3 "https://www.vishay.com/docs/83526/83526.pdf" H 3700 3250 50  0001 C CNN
	1    3700 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 60C808ED
P 3250 3150
F 0 "R1" V 3457 3150 50  0000 C CNN
F 1 "R" V 3366 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3180 3150 50  0001 C CNN
F 3 "~" H 3250 3150 50  0001 C CNN
	1    3250 3150
	0    -1   -1   0   
$EndComp
Text GLabel 3900 3350 2    50   Input ~ 0
GND
Wire Wire Line
	4700 2800 4000 2800
$Comp
L Device:R R2
U 1 1 60C8CC75
P 3650 2800
F 0 "R2" V 3857 2800 50  0000 C CNN
F 1 "R" V 3766 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3580 2800 50  0001 C CNN
F 3 "~" H 3650 2800 50  0001 C CNN
	1    3650 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3500 2800 3500 2450
Wire Wire Line
	3500 2450 4550 2450
Connection ~ 4550 2450
Wire Wire Line
	4550 2450 4550 2300
$Comp
L Connector:RJ45_LED J1
U 1 1 60C9C966
P 7050 2100
F 0 "J1" H 7050 1533 50  0000 C CNN
F 1 "RJ45_LED" H 7050 1624 50  0000 C CNN
F 2 "customs:RND_RJ45_LED" V 7050 2125 50  0001 C CNN
F 3 "~" V 7050 2125 50  0001 C CNN
	1    7050 2100
	-1   0    0    1   
$EndComp
Wire Wire Line
	3900 3150 4000 3150
Wire Wire Line
	4000 3150 4000 2800
Connection ~ 4000 2800
Wire Wire Line
	4000 2800 3800 2800
Text Label 3100 3150 2    50   ~ 0
sense+
Text Label 3400 3350 2    50   ~ 0
sense-
$Comp
L Device:R R3
U 1 1 60CC2A3C
P 4700 1650
F 0 "R3" V 4907 1650 50  0000 C CNN
F 1 "R" V 4816 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4630 1650 50  0001 C CNN
F 3 "~" H 4700 1650 50  0001 C CNN
	1    4700 1650
	0    -1   -1   0   
$EndComp
Text GLabel 5350 1850 2    50   Input ~ 0
GND
Text Label 4550 1650 2    50   ~ 0
sense+
Text Label 4850 1850 2    50   ~ 0
sense-
Wire Wire Line
	8650 1800 9400 1800
Text Label 5350 1650 0    60   ~ 0
Reset
$Comp
L Connector:RJ45_LED J2
U 1 1 60CD0755
P 7050 3550
F 0 "J2" H 7050 2983 50  0000 C CNN
F 1 "RJ45_LED" H 7050 3074 50  0000 C CNN
F 2 "customs:RND_RJ45_LED" V 7050 3575 50  0001 C CNN
F 3 "~" V 7050 3575 50  0001 C CNN
	1    7050 3550
	-1   0    0    1   
$EndComp
Text Label 6650 2200 2    50   ~ 0
sense-
Text Label 6650 2500 2    50   ~ 0
sense+
Text Label 7750 2400 0    50   ~ 0
sense+
$Comp
L Device:R R4
U 1 1 60CD3FE0
P 7600 1800
F 0 "R4" V 7393 1800 50  0000 C CNN
F 1 "R" V 7484 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7530 1800 50  0001 C CNN
F 3 "~" H 7600 1800 50  0001 C CNN
	1    7600 1800
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 60CD6AD0
P 7600 2400
F 0 "R5" V 7393 2400 50  0000 C CNN
F 1 "R" V 7484 2400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7530 2400 50  0001 C CNN
F 3 "~" H 7600 2400 50  0001 C CNN
	1    7600 2400
	0    1    1    0   
$EndComp
Text Label 7750 1800 0    50   ~ 0
sense+
Text Label 6650 3650 2    50   ~ 0
sense-B
Text Label 6650 3950 2    50   ~ 0
sense+B
Text Label 7450 1900 0    50   ~ 0
sense-
Text Label 7450 2500 0    50   ~ 0
sense-
$Comp
L Device:R R8
U 1 1 60CDE53E
P 7600 3250
F 0 "R8" V 7393 3250 50  0000 C CNN
F 1 "R" V 7484 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7530 3250 50  0001 C CNN
F 3 "~" H 7600 3250 50  0001 C CNN
	1    7600 3250
	0    1    1    0   
$EndComp
Text Label 7750 3250 0    50   ~ 0
sense+B
Text Label 7450 3350 0    50   ~ 0
sense-B
$Comp
L Device:R R9
U 1 1 60CE5241
P 7600 3850
F 0 "R9" V 7393 3850 50  0000 C CNN
F 1 "R" V 7484 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7530 3850 50  0001 C CNN
F 3 "~" H 7600 3850 50  0001 C CNN
	1    7600 3850
	0    1    1    0   
$EndComp
Text Label 7750 3850 0    50   ~ 0
sense+B
Text Label 7450 3950 0    50   ~ 0
sense-B
$Comp
L custom:CNY74-2H OC2
U 1 1 60CEB5BF
P 3700 3800
F 0 "OC2" H 3650 4125 50  0000 C CNN
F 1 "CNY74-2H" H 3650 4034 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_LongPads" H 3700 3800 50  0001 C CNN
F 3 "https://www.vishay.com/docs/83526/83526.pdf" H 3700 3800 50  0001 C CNN
	1    3700 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 60CEB5C5
P 3250 3700
F 0 "R6" V 3457 3700 50  0000 C CNN
F 1 "R" V 3366 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3180 3700 50  0001 C CNN
F 3 "~" H 3250 3700 50  0001 C CNN
	1    3250 3700
	0    -1   -1   0   
$EndComp
Text Label 3100 3700 2    50   ~ 0
sense+B
Text Label 3400 3900 2    50   ~ 0
sense-B
Wire Wire Line
	3900 3700 4250 3700
Wire Wire Line
	4250 3700 4250 3150
Wire Wire Line
	4250 3150 4000 3150
Connection ~ 4000 3150
Text GLabel 3900 3900 2    50   Input ~ 0
GND
$Comp
L custom:CNY74-2H OC2
U 2 1 60CF299E
P 5150 1200
F 0 "OC2" H 5100 1525 50  0000 C CNN
F 1 "CNY74-2H" H 5100 1434 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_LongPads" H 5150 1200 50  0001 C CNN
F 3 "https://www.vishay.com/docs/83526/83526.pdf" H 5150 1200 50  0001 C CNN
	2    5150 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 60CF29A4
P 4700 1100
F 0 "R7" V 4907 1100 50  0000 C CNN
F 1 "R" V 4816 1100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4630 1100 50  0001 C CNN
F 3 "~" H 4700 1100 50  0001 C CNN
	1    4700 1100
	0    -1   -1   0   
$EndComp
Text GLabel 5350 1300 2    50   Input ~ 0
GND
Text Label 4550 1100 2    50   ~ 0
sense+B
Text Label 4850 1300 2    50   ~ 0
sense-B
Text Label 5350 1100 0    60   ~ 0
Reset
$Comp
L Connector:AVR-ISP-6 J3
U 1 1 60D0D8E4
P 9300 4650
F 0 "J3" H 8971 4746 50  0000 R CNN
F 1 "AVR-ISP-6" H 8971 4655 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x03_P2.54mm_Vertical" V 9050 4700 50  0001 C CNN
F 3 " ~" H 8025 4100 50  0001 C CNN
	1    9300 4650
	1    0    0    -1  
$EndComp
Text Label 9700 4650 0    60   ~ 0
13(SCK)
Text Label 9700 4450 0    60   ~ 0
12(MISO)
Text Label 9700 4550 0    60   ~ 0
11(**/MOSI)
Text Label 9700 4750 0    60   ~ 0
10(**/SS)
Text GLabel 9200 4150 1    50   Input ~ 0
5V
Text GLabel 9200 5050 3    50   Input ~ 0
GND
$Comp
L Diode:1N4001 D1
U 1 1 60C17D76
P 5800 2400
F 0 "D1" H 5800 2300 50  0000 C CNN
F 1 "1N4001" H 5800 2550 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P3.81mm_Vertical_KathodeUp" H 5800 2225 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 5800 2400 50  0001 C CNN
	1    5800 2400
	-1   0    0    1   
$EndComp
$EndSCHEMATC
