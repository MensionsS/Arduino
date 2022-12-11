#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int imp = 0;
int l = 0;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const int pinButton = 6;




void setup()
{
    lcd.begin(5, 3);
    lcd.setRGB(colorR, colorG, colorB);
    Serial.begin(9600);                         
    pinMode(pinButton, INPUT);
}

void loop()
{

  if (digitalRead(pinButton = HIGH)) {
    imp = imp+1;
  } else {
    lcd.setCursor(0, 1); 
    Serial.println("RIEN");
    lcd.print("TEST");
  }


  lcd.setCursor(0, 1); 
  lcd.print(imp);


    delay(300);
    lcd.clear();
    
}
