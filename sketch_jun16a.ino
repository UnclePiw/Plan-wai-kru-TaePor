#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int in1=11;
int in2=10;

LiquidCrystal_I2C lcd(0x27, 20, 4);

byte customChar8[8] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00100,
  B00100,
  B00110,
  B00110
};//เ

byte customChar9[8] = {
  B00100,
  B01110,
  B00100,
  B01010,
  B10101,
  B10101,
  B11001,
  B10001
};//ต๋

byte customChar10[8] = {
  B00001,
  B00001,
  B00001,
  B11001,
  B11001,
  B01001,
  B01001,
  B01111
}; //ป

byte customChar11[8] = {
  B00000,
  B00000,
  B00000,
  B11110,
  B00010,
  B11010,
  B10010,
  B11110
};//อ 


void setup()
{
Serial.begin(9600);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
lcd.init();
lcd.backlight();
lcd.createChar(0, customChar8); //เ
lcd.createChar(1, customChar9); //ต๋
lcd.createChar(2, customChar10); //ป
lcd.createChar(3, customChar11); //อ


lcd.setCursor(5,0);
lcd.write((uint8_t)0);
lcd.write((uint8_t)1);
lcd.write((uint8_t)2);
lcd.write((uint8_t)3);
lcd.setCursor(4,1);
lcd.print("Hotpot");
}

void loop() 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);
}


