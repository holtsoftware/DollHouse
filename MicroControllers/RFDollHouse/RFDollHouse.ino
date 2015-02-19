#include <RFduinoBLE\RFduinoBLE.h>
#include <libRFduino.h>
#include <Wire\Wire.h>
#include "DollHouse.h"
#include "Message.h"

void setup()
{
	/* add setup code here */
	RFduinoBLE.deviceName = "DollHouse";
	RFduinoBLE.advertisementData = "data";
	RFduinoBLE.advertisementInterval = MILLISECONDS(300);
	RFduinoBLE.txPowerLevel = -20;  // (-20dbM to +4 dBm)

	RFduinoBLE.begin();
	Wire.begin();
	Wire.onReceive(busReceiveEvent);

	pinMode(0, OUTPUT);
}

void loop()
{
	/* add main program code here */
	RFduino_ULPDelay(SECONDS(1));

	float temp = RFduino_temperature(CELSIUS);

	RFduinoBLE.sendFloat(temp);

	long l = long(temp * 100);

	Wire.beginTransmission(MVAddress);
	Wire.write(l);
	Wire.endTransmission();

	digitalWrite(0, HIGH);

	RFduino_ULPDelay(SECONDS(1));

	digitalWrite(0, LOW);
}

void busReceiveEvent(int count)
{
	Message m;
	/*while (1 < Wire.available()) // loop through all but the last
	{
		char c = Wire.read(); // receive byte as a character
		Serial.print(c);         // print the character
	}
	int x = Wire.read();    // receive byte as an integer
	Serial.println(x);*/
}

/*void RFduinoBLE_onAdvertisement(bool start)
{
}*/

/*void RFduinoBLE_onConnect()
{
}*/

/*void RFduinoBLE_onDisconnect()
{
}*/

// returns the dBm signal strength indicated by the receiver after connection (-0dBm to -127dBm)
/*void RFduinoBLE_onRSSI(int rssi)
{
}*/

/*void RFduinoBLE_onReceive(char *data, int len)
{
}*/