#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = A0;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HPP Tecnologia  ");
  lcd.setCursor(0, 1);
  /*lcd.print("****************");*/
  lcd.print("Fluxo Agua Meter");
  delay(2000);
  pinMode(input, INPUT);
}
void loop()
{
  X = pulseIn(input, HIGH);
  Y = pulseIn(input, LOW);
  TIME = X + Y;
  FREQUENCY = 1000000 / TIME;
  WATER = FREQUENCY / 7.5;
  LS = WATER / 60;
  if (FREQUENCY >= 0)
  {
    if (isinf(FREQUENCY))
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fluxo: 0.00");
      lcd.setCursor(0, 1);
      lcd.print("Total: ");
      lcd.print( TOTAL);
      lcd.print(" Lts");
    }
    else
    {
      TOTAL = TOTAL + LS;
      Serial.println(FREQUENCY);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("FLUXO: ");
      lcd.print(WATER);
      lcd.print(" L/M");
      lcd.setCursor(0, 1);
      lcd.print("TOTAL: ");
      lcd.print( TOTAL);
      lcd.print(" Lts");
    }
  }
  delay(1000);
}
