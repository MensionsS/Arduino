#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int potentiometer = A0;  
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const int pinButton = 2;
const int relayPin =  8;




void setup()
{
    lcd.begin(5, 3);
    lcd.setRGB(colorR, colorG, colorB);
    Serial.begin(9600);                         
    pinMode(potentiometer, INPUT);
    pinMode(pinButton, INPUT);
    pinMode(relayPin, OUTPUT);

}

void loop()
{
    float fuel = analogRead(potentiometer);
    int km = analogRead(potentiometer);
    int kmmap;
    kmmap = map(km, 0, 1023,0,200);
    kmmap = kmmap;

    fuel = fuel/20;
    bool statut = 0;

    if(fuel <5)
    {
    lcd.setCursor(0, 0);
    lcd.print(fuel);
    digitalWrite(relayPin, HIGH);
    statut = 1;
    }
    else
   {
    lcd.setCursor(0, 0);
    lcd.print(fuel);
    lcd.print("L");
    digitalWrite(relayPin, LOW);
    }

   if (statut = 1 && fuel <7)
    {
    lcd.setCursor(0, 0); 
    lcd.print(fuel);
    lcd.print("L");
    digitalWrite(relayPin, HIGH);
    } else{
    lcd.setCursor(0, 0); 
    lcd.print(fuel);
    lcd.print("L");
    statut = 0;
    digitalWrite(relayPin, LOW);
    }

    lcd.setCursor(0, 1);
    lcd.print(kmmap);
    lcd.print("km");



     delay(700);
     lcd.clear();  
}
