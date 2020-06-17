/*
 Name:		VescUartSample.ino
 Created:	9/26/2015 10:12:38 PM
 Author:	AC
*/

//Include libraries copied from VESC
 #include "VescUart.h"
#include "datatypes.h"


#define DEBUG
unsigned long count;

void setup() {
	
	//Setup UART port
	Serial1.begin(115200);
#ifdef DEBUG
	//SEtup debug port
	Serial.begin(115200);
	#endif
}

struct bldcMeasure measuredValues;
	
void loop() {
	if (VescUartGetValue(measuredValues)) {
		Serial.print("Loop: "); Serial.println(count++);
		SerialPrint(measuredValues);
	}
	else
	{
		Serial.println("Failed to get data!");
	}
	
}





