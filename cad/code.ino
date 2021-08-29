#include <Wire.h>
#include "Adafruit_NeoPixel.h"
#include "RTClib.h"
#define pbws 3
#define PIN 5
#define PIN1 6
#define PIN2 8
#define NUM_LEDS1 6
#define NUM_LEDS2 6
#define NUM_LEDS3 11
#define ph 4
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS1, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS2, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUM_LEDS3, PIN2, NEO_GRB + NEO_KHZ800);

RTC_DS3231 rtc;
unsigned int t,m,h,p;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () 
{
  pinMode(pbws,INPUT_PULLUP);
  pinMode(ph,INPUT_PULLUP);
  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show();
  Serial.begin(9600);
  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
	
	// Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime());
	
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
    // rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
  }
}


// this one for timing second 
void tim(void)
{
    DateTime now = rtc.now();
    Serial.println("Current Date & Time: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    t=now.second();
    if(t==10)
    {
      strip1.setPixelColor(0,50,0,0);
      strip1.show();

    } 
        if(t==20)
    {
      strip1.setPixelColor(1,50,0,0);
      strip1.show();
    } 
       if(t==30)
    {
      strip1.setPixelColor(2,50,0,0);
      strip1.show();
    } 
           if(t==40)
    {
      strip1.setPixelColor(3,50,0,0);
      strip1.show();
    } 
       if(t==50)
    {
      strip1.setPixelColor(4,50,0,0);
      strip1.show();
    } 
if(t==0)
    {
      strip1.setPixelColor(0,0,0,0);
      strip1.show();
      strip1.setPixelColor(1,0,0,0);
      strip1.show(); 
      strip1.setPixelColor(2,0,0,0);
      strip1.show(); 
      strip1.setPixelColor(3,0,0,0);
      strip1.show();
      strip1.setPixelColor(4,0,0,0);
      strip1.show();
    } 
}

//this one for the minute hand 
void mi(void)
{
  unsigned int q;
  DateTime now = rtc.now();
 p=now.second();
if(p == 0)
{
  q=q+1;
  }
  strip3.setPixelColor(q,50,0,0);
  strip3.show();
  if(q==3)
  {
     strip3.setPixelColor(1,0,0,0);
  strip3.show();
    strip3.setPixelColor(2,0,0,0);
  strip3.show();
q=0;  
  }
} 

// this one for timing min
void mine(void)
{
    DateTime now = rtc.now();

    m=now.minute();
    if(m>=10)
    {
      strip2.setPixelColor(0,50,0,0);
      strip2.show();

    } 
        if(m>=20)
    {
      strip2.setPixelColor(1,50,0,0);
      strip2.show();
    } 
       if(m>=30)
    {
      strip2.setPixelColor(2,50,0,0);
      strip2.show();
    } 
      if(m>=40)
    {
      strip2.setPixelColor(3,50,0,0);
      strip2.show();
    } 
       if(m>=50)
    {
      strip2.setPixelColor(4,50,0,0);
      strip2.show();
    } 
if(m==0)
    {
      strip2.setPixelColor(0,0,0,0);
      strip2.show();
      strip2.setPixelColor(1,0,0,0);
      strip2.show(); 
      strip2.setPixelColor(2,0,0,0);
      strip2.show(); 
      strip2.setPixelColor(3,0,0,0);
      strip2.show();
      strip2.setPixelColor(4,0,0,0);
      strip2.show();
      strip2.setPixelColor(5,0,0,0);
      strip2.show();
    } 
}

// this one for timing hour
void hr(void)
{
    DateTime now = rtc.now();

    h=now.hour();
    if(h==1 || h==13)
    {
      strip3.setPixelColor(0,50,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();

    } 
        if(h==2 || h==14)
    {
      strip3.setPixelColor(1,50,0,0);
      strip3.show();
            strip3.setPixelColor(0,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
       if(h==3 || h==15)
    {
      strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,50,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
           if(h==4 || h==16)
    {
      strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,50,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
       if(h==5 || h==17)
    {
       strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,50,0,0);
      strip3.show();
                  strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
              strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
           if(h==6 || h==18)
    {
       strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,50,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
           if(h==7 || h==19)
    {
      strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,50,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
           if(h==8 || h==20)
    {
      strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,50,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
           if(h==9 || h==21)
    {
      strip3.setPixelColor(8,50,0,0);
      strip3.show();      
      strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
       if(h==10 || h==22)
    {
      strip3.setPixelColor(9,50,0,0);
      strip3.show();
            strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
           if(h==11 || h==23)
    {
      strip3.setPixelColor(10,50,0,0);
      strip3.show();
            strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(11,0,0,0);
      strip3.show();
    } 
           if(h==12 || h==00)
    {
      strip3.setPixelColor(11,50,0,0);
      strip3.show();
            strip3.setPixelColor(0,0,0,0);
      strip3.show();
      strip3.setPixelColor(1,0,0,0);
      strip3.show();
            strip3.setPixelColor(2,0,0,0);
      strip3.show();
            strip3.setPixelColor(3,0,0,0);
      strip3.show();
            strip3.setPixelColor(4,0,0,0);
      strip3.show();
            strip3.setPixelColor(5,0,0,0);
      strip3.show();
            strip3.setPixelColor(6,0,0,0);
      strip3.show();
            strip3.setPixelColor(7,0,0,0);
      strip3.show();
            strip3.setPixelColor(8,0,0,0);
      strip3.show();
            strip3.setPixelColor(9,0,0,0);
      strip3.show();
            strip3.setPixelColor(10,0,0,0);
      strip3.show();
    } 
}


void loop () 
{
  if(digitalRead(pbws)==LOW)
  {
    while(1)
    {
tim();
mine();
hr();
    }
  }
    Serial.println();
    delay(1000);
}