#include <Wire\Wire.h>
#include "DollHouse.h"
#include <MicroView\MicroView.h>
#include "Message.h"

long temp = 0;
int arraySize = sizeof(long);
char tmpTemp[sizeof(long)];

void setup()
{
	/* add setup code here */
	uView.begin();
	uView.print("Starting...");
	uView.display();
	Wire.begin(MVAddress);
	Wire.onReceive(dataReceived);
}

void loop()
{
	if (temp != 0)
	{
		uView.print("Temp ");
		uView.print(temp);
		uView.display();
	}
	delay(500);
}

void dataReceived(int numBytes)
{
	Message m;
	for (int i = 0; i < arraySize; i++)
	{
		tmpTemp[i] = 0;
	}

	int current = 0;

	while (1 < Wire.available())
	{
		tmpTemp[current++] = Wire.read();
	}

	m.Data = tmpTemp[0] | tmpTemp[1] << 8 | tmpTemp[2] << 16 | tmpTemp[3] << 24;
	temp = m.Data / 100;
}
