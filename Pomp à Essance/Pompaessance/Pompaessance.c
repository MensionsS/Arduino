#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int imp = 0;
int l = 0;
int prixf = 0;
const int prix = 2;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const int pinButton = 6;




void setup()    {
    lcd.begin(5, 3);
    lcd.setRGB(colorR, colorG, colorB);
    Serial.begin(9600);                         
    pinMode(pinButton, INPUT);
}

function affichage

void loop()     {

    if (digitalRead(pinButton)) {
        imp = imp+1;
        Serial.print("test");
    } else {
        Serial.print("Rien");
    }

    if (imp == 3)   {
        imp = 0;
        l=l+1;
        prixf = l*prix;
    } else {
        Serial.print("rien");
    }
  
lcd.setCursor(0,0);
lcd.print(l);
lcd.print("Litre");
lcd.print(imp);
lcd.setCursor(0, 1); 
lcd.print("prix =");
lcd.print(prixf);
lcd.print("euro");
delay(50);
lcd.clear(); 
}
