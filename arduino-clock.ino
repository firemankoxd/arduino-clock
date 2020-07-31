#include <Wire.h>
#include <DS3231.h>
#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3
#define UPDATECYCLE 1000

DS3231 clock;
RTCDateTime dt;
TM1637Display display(CLK, DIO);
 
char Time24 [16]; //TOTO POJDE PREC
uint8_t Min, Hour, Sec;
uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
int Hour1, Hour2, Min1, Min2, dispNumber;

void setup()
{
 clock.begin();
 //clock.setDateTime(2020, 7, 23, 20, 14, 40);  //NASTAVENIE CASU (UZ ASI NETREBA)
 display.setBrightness(7);
}

void loop()
{
 dt = clock.getDateTime();
 Min = dt.minute;
 Hour = dt.hour;
 Hour1=Hour/10;
 Hour2=Hour-Hour1*10;
 Min1=Min/10;
 Min2=Min-Min1*10;
 dispNumber = Hour1*1000+Hour2*100+Min1*10+Min2;
 display.showNumberDecEx(dispNumber, 0b01000000, true, 4, 0);
 delay(UPDATECYCLE);
}
