EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
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
L 74xx:74HC595 U5
U 1 1 60CC9D5F
P 1450 2550
F 0 "U5" H 1250 3150 50  0000 C CNN
F 1 "74HC595" H 1650 3150 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 1450 2550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 1450 2550 50  0001 C CNN
	1    1450 2550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U6
U 1 1 60CCB7E4
P 1450 4450
F 0 "U6" H 1200 5050 50  0000 C CNN
F 1 "74HC595" H 1650 5050 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 1450 4450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 1450 4450 50  0001 C CNN
	1    1450 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J5
U 1 1 60CCEB86
P 3000 3400
F 0 "J5" H 3050 3917 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 3050 3826 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 3000 3400 50  0001 C CNN
F 3 "~" H 3000 3400 50  0001 C CNN
	1    3000 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 3100 2100 3100
Wire Wire Line
	2100 3100 2100 2150
Wire Wire Line
	2100 2150 1850 2150
Wire Wire Line
	1850 2250 3550 2250
Wire Wire Line
	3550 2250 3550 3100
Wire Wire Line
	3550 3100 3300 3100
Wire Wire Line
	2800 3200 2050 3200
Wire Wire Line
	2050 3200 2050 2350
Wire Wire Line
	2050 2350 1850 2350
Wire Wire Line
	1850 2450 3600 2450
Wire Wire Line
	3600 2450 3600 3200
Wire Wire Line
	3600 3200 3300 3200
Wire Wire Line
	2800 3300 2000 3300
Wire Wire Line
	2000 3300 2000 2550
Wire Wire Line
	2000 2550 1850 2550
Wire Wire Line
	1850 2650 3650 2650
Wire Wire Line
	3650 2650 3650 3300
Wire Wire Line
	3650 3300 3300 3300
Wire Wire Line
	2800 3400 1950 3400
Wire Wire Line
	1950 3400 1950 2750
Wire Wire Line
	1950 2750 1850 2750
Wire Wire Line
	1850 2850 3700 2850
Wire Wire Line
	3700 2850 3700 3400
Wire Wire Line
	3700 3400 3300 3400
Wire Wire Line
	2800 3500 1950 3500
Wire Wire Line
	1950 3500 1950 4050
Wire Wire Line
	1950 4050 1850 4050
Wire Wire Line
	1850 4150 3550 4150
Wire Wire Line
	3550 4150 3550 3500
Wire Wire Line
	3550 3500 3300 3500
Wire Wire Line
	2800 3600 2000 3600
Wire Wire Line
	2000 3600 2000 4250
Wire Wire Line
	2000 4250 1850 4250
Wire Wire Line
	1850 4350 3600 4350
Wire Wire Line
	3600 4350 3600 3600
Wire Wire Line
	3600 3600 3300 3600
Wire Wire Line
	2800 3700 2050 3700
Wire Wire Line
	2050 3700 2050 4450
Wire Wire Line
	2050 4450 1850 4450
Wire Wire Line
	1850 4650 2100 4650
Wire Wire Line
	2100 4650 2100 3800
Wire Wire Line
	2100 3800 2800 3800
Wire Wire Line
	1850 4550 3650 4550
Wire Wire Line
	3650 4550 3650 3700
Wire Wire Line
	3650 3700 3300 3700
Wire Wire Line
	3300 3800 3700 3800
Wire Wire Line
	3700 3800 3700 4750
Wire Wire Line
	3700 4750 1850 4750
Wire Wire Line
	1850 3050 1850 3500
Wire Wire Line
	1850 3500 1050 3500
Wire Wire Line
	1050 3500 1050 4050
Text GLabel 1450 1800 1    50   Input ~ 0
5V
Wire Wire Line
	1450 1800 1450 1950
Text GLabel 1450 3700 1    50   Input ~ 0
5V
Wire Wire Line
	1450 3700 1450 3850
Text GLabel 1450 3250 3    50   Input ~ 0
GND
Text GLabel 1450 5150 3    50   Input ~ 0
GND
Text HLabel 1050 4650 0    50   Input ~ 0
~OE
Text HLabel 1050 2750 0    50   Input ~ 0
~OE
Text HLabel 1050 2350 0    50   Input ~ 0
Clock
Text HLabel 1050 4250 0    50   Input ~ 0
Clock
Text GLabel 1050 4350 0    50   Input ~ 0
5V
Text GLabel 1050 2450 0    50   Input ~ 0
5V
Text HLabel 1050 2150 0    50   Input ~ 0
Serial_In
Text HLabel 1050 2650 0    50   Input ~ 0
Latch
Text HLabel 1050 4550 0    50   Input ~ 0
Latch
$Comp
L 74xx:74HC595 U7
U 1 1 60D00BA5
P 4550 2550
F 0 "U7" H 4350 3150 50  0000 C CNN
F 1 "74HC595" H 4750 3150 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 4550 2550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4550 2550 50  0001 C CNN
	1    4550 2550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U8
U 1 1 60D00BAB
P 4550 4450
F 0 "U8" H 4300 5050 50  0000 C CNN
F 1 "74HC595" H 4750 5050 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 4550 4450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 4550 4450 50  0001 C CNN
	1    4550 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J6
U 1 1 60D00BB1
P 6100 3400
F 0 "J6" H 6150 3917 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 6150 3826 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 6100 3400 50  0001 C CNN
F 3 "~" H 6100 3400 50  0001 C CNN
	1    6100 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3100 5200 3100
Wire Wire Line
	5200 3100 5200 2150
Wire Wire Line
	5200 2150 4950 2150
Wire Wire Line
	4950 2250 6650 2250
Wire Wire Line
	6650 2250 6650 3100
Wire Wire Line
	6650 3100 6400 3100
Wire Wire Line
	5900 3200 5150 3200
Wire Wire Line
	5150 3200 5150 2350
Wire Wire Line
	5150 2350 4950 2350
Wire Wire Line
	4950 2450 6700 2450
Wire Wire Line
	6700 2450 6700 3200
Wire Wire Line
	6700 3200 6400 3200
Wire Wire Line
	5900 3300 5100 3300
Wire Wire Line
	5100 3300 5100 2550
Wire Wire Line
	5100 2550 4950 2550
Wire Wire Line
	4950 2650 6750 2650
Wire Wire Line
	6750 2650 6750 3300
Wire Wire Line
	6750 3300 6400 3300
Wire Wire Line
	5900 3400 5050 3400
Wire Wire Line
	5050 3400 5050 2750
Wire Wire Line
	5050 2750 4950 2750
Wire Wire Line
	4950 2850 6800 2850
Wire Wire Line
	6800 2850 6800 3400
Wire Wire Line
	6800 3400 6400 3400
Wire Wire Line
	5900 3500 5050 3500
Wire Wire Line
	5050 3500 5050 4050
Wire Wire Line
	5050 4050 4950 4050
Wire Wire Line
	4950 4150 6650 4150
Wire Wire Line
	6650 4150 6650 3500
Wire Wire Line
	6650 3500 6400 3500
Wire Wire Line
	5900 3600 5100 3600
Wire Wire Line
	5100 3600 5100 4250
Wire Wire Line
	5100 4250 4950 4250
Wire Wire Line
	4950 4350 6700 4350
Wire Wire Line
	6700 4350 6700 3600
Wire Wire Line
	6700 3600 6400 3600
Wire Wire Line
	5900 3700 5150 3700
Wire Wire Line
	5150 3700 5150 4450
Wire Wire Line
	5150 4450 4950 4450
Wire Wire Line
	4950 4650 5200 4650
Wire Wire Line
	5200 4650 5200 3800
Wire Wire Line
	5200 3800 5900 3800
Wire Wire Line
	4950 4550 6750 4550
Wire Wire Line
	6750 4550 6750 3700
Wire Wire Line
	6750 3700 6400 3700
Wire Wire Line
	6400 3800 6800 3800
Wire Wire Line
	6800 3800 6800 4750
Wire Wire Line
	6800 4750 4950 4750
Wire Wire Line
	4950 3050 4950 3500
Wire Wire Line
	4950 3500 4150 3500
Wire Wire Line
	4150 3500 4150 4050
Text GLabel 4550 1800 1    50   Input ~ 0
5V
Wire Wire Line
	4550 1800 4550 1950
Text GLabel 4550 3700 1    50   Input ~ 0
5V
Wire Wire Line
	4550 3700 4550 3850
Text GLabel 4550 3250 3    50   Input ~ 0
GND
Text GLabel 4550 5150 3    50   Input ~ 0
GND
Text HLabel 4150 4650 0    50   Input ~ 0
~OE
Text HLabel 4150 2750 0    50   Input ~ 0
~OE
Text HLabel 4150 2350 0    50   Input ~ 0
Clock
Text HLabel 4150 4250 0    50   Input ~ 0
Clock
Text GLabel 4150 4350 0    50   Input ~ 0
5V
Text GLabel 4150 2450 0    50   Input ~ 0
5V
Text HLabel 4150 2650 0    50   Input ~ 0
Latch
Text HLabel 4150 4550 0    50   Input ~ 0
Latch
$Comp
L 74xx:74HC595 U9
U 1 1 60D08981
P 7950 2550
F 0 "U9" H 7750 3150 50  0000 C CNN
F 1 "74HC595" H 8150 3150 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 7950 2550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 7950 2550 50  0001 C CNN
	1    7950 2550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U10
U 1 1 60D08987
P 7950 4450
F 0 "U10" H 7700 5050 50  0000 C CNN
F 1 "74HC595" H 8150 5050 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 7950 4450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 7950 4450 50  0001 C CNN
	1    7950 4450
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J7
U 1 1 60D0898D
P 9500 3400
F 0 "J7" H 9550 3917 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 9550 3826 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 9500 3400 50  0001 C CNN
F 3 "~" H 9500 3400 50  0001 C CNN
	1    9500 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3100 8600 3100
Wire Wire Line
	8600 3100 8600 2150
Wire Wire Line
	8600 2150 8350 2150
Wire Wire Line
	8350 2250 10050 2250
Wire Wire Line
	10050 2250 10050 3100
Wire Wire Line
	10050 3100 9800 3100
Wire Wire Line
	9300 3200 8550 3200
Wire Wire Line
	8550 3200 8550 2350
Wire Wire Line
	8550 2350 8350 2350
Wire Wire Line
	8350 2450 10100 2450
Wire Wire Line
	10100 2450 10100 3200
Wire Wire Line
	10100 3200 9800 3200
Wire Wire Line
	9300 3300 8500 3300
Wire Wire Line
	8500 3300 8500 2550
Wire Wire Line
	8500 2550 8350 2550
Wire Wire Line
	8350 2650 10150 2650
Wire Wire Line
	10150 2650 10150 3300
Wire Wire Line
	10150 3300 9800 3300
Wire Wire Line
	9300 3400 8450 3400
Wire Wire Line
	8450 3400 8450 2750
Wire Wire Line
	8450 2750 8350 2750
Wire Wire Line
	8350 2850 10200 2850
Wire Wire Line
	10200 2850 10200 3400
Wire Wire Line
	10200 3400 9800 3400
Wire Wire Line
	9300 3500 8450 3500
Wire Wire Line
	8450 3500 8450 4050
Wire Wire Line
	8450 4050 8350 4050
Wire Wire Line
	8350 4150 10050 4150
Wire Wire Line
	10050 4150 10050 3500
Wire Wire Line
	10050 3500 9800 3500
Wire Wire Line
	9300 3600 8500 3600
Wire Wire Line
	8500 3600 8500 4250
Wire Wire Line
	8500 4250 8350 4250
Wire Wire Line
	8350 4350 10100 4350
Wire Wire Line
	10100 4350 10100 3600
Wire Wire Line
	10100 3600 9800 3600
Wire Wire Line
	9300 3700 8550 3700
Wire Wire Line
	8550 3700 8550 4450
Wire Wire Line
	8550 4450 8350 4450
Wire Wire Line
	8350 4650 8600 4650
Wire Wire Line
	8600 4650 8600 3800
Wire Wire Line
	8600 3800 9300 3800
Wire Wire Line
	8350 4550 10150 4550
Wire Wire Line
	10150 4550 10150 3700
Wire Wire Line
	10150 3700 9800 3700
Wire Wire Line
	9800 3800 10200 3800
Wire Wire Line
	10200 3800 10200 4750
Wire Wire Line
	10200 4750 8350 4750
Wire Wire Line
	8350 3050 8350 3500
Wire Wire Line
	8350 3500 7550 3500
Wire Wire Line
	7550 3500 7550 4050
Text GLabel 7950 1800 1    50   Input ~ 0
5V
Wire Wire Line
	7950 1800 7950 1950
Text GLabel 7950 3700 1    50   Input ~ 0
5V
Wire Wire Line
	7950 3700 7950 3850
Text GLabel 7950 3250 3    50   Input ~ 0
GND
Text GLabel 7950 5150 3    50   Input ~ 0
GND
Text HLabel 7550 4650 0    50   Input ~ 0
~OE
Text HLabel 7550 2750 0    50   Input ~ 0
~OE
Text HLabel 7550 2350 0    50   Input ~ 0
Clock
Text HLabel 7550 4250 0    50   Input ~ 0
Clock
Text GLabel 7550 4350 0    50   Input ~ 0
5V
Text GLabel 7550 2450 0    50   Input ~ 0
5V
Text HLabel 7550 2650 0    50   Input ~ 0
Latch
Text HLabel 7550 4550 0    50   Input ~ 0
Latch
Wire Wire Line
	4150 2150 3850 2150
Wire Wire Line
	3850 2150 3850 4950
Wire Wire Line
	3850 4950 1850 4950
Wire Wire Line
	7550 2150 7250 2150
Wire Wire Line
	7250 2150 7250 4950
Wire Wire Line
	7250 4950 4950 4950
$EndSCHEMATC
