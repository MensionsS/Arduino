#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int potentiometer = A0;  
const int colorR = 143;
const int colorG = 0;
const int colorB = 255;
const int pinButton = 2;




void setup() {
    lcd.begin(5, 3);
    lcd.setRGB(colorR, colorG, colorB);
    Serial.begin(9600);                         
    pinMode(potentiometer, INPUT);
    pinMode(pinButton, INPUT);

}

void loop() {
    int temp = analogRead(potentiometer);
    float tempd = analogRead(potentiometer);


    temp = temp/10;
    temp = temp-25;

    tempd = tempd/10;
    tempd = tempd-25;

    lcd.print(temp);
    lcd.write((char)223);
    lcd.print("C ");
    lcd.print(tempd);
    lcd.write((char)223);
    lcd.print("C ");
    delay(700);
    lcd.clear(); 
}
