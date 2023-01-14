#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int potentiometer = A0;  
const int colorR = 143;
const int colorG = 0;
const int colorB = 255;
const int pinButton = 2;



void setup()    {
    lcd.begin(5, 3);
    lcd.setRGB(colorR, colorG, colorB);
    Serial.begin(9600);                         
    pinMode(potentiometer, INPUT);
    pinMode(pinButton, INPUT);
}

void loop()   {
int vitesse = analogRead(potentiometer);
float dvitesse = analogRead(potentiometer);

    
dvitesse = dvitesse/10;
vitesse = vitesse/3;

if(digitalRead(pinButton))  {
    lcd.setCursor(0, 0);
    lcd.print(vitesse);
    lcd.print("km/h");
      if (vitesse > 50) {
          lcd.setCursor(0, 1);
          lcd.print("Trop Rapide");
      } else{
          lcd.setCursor(0, 1);
      }
    } else{
    lcd.setCursor(0, 0);
    lcd.print(dvitesse);
    lcd.print("km/h");
        if (dvitesse > 50) {
          lcd.setCursor(0, 1);
          lcd.print("Trop Rapide");
        } else{
          lcd.setCursor(0, 1);
        }
   }
delay(700);
lcd.clear();  
}
