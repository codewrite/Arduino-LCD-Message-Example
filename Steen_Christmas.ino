#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  // adjust this to suit your pins.

void setup()
{
  // put your setup code here, to run once:
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
}

int step = 0;
bool restart = false;

void loop()
{
  // put your main code here, to run repeatedly:

  if (step == 0)
  {
    if (restart)
    {
      lcd.setCursor(0, 0);
      lcd.print(F("From Jon        Happy Christmas"));
      lcd.setCursor(0, 1);
      lcd.print(F("  and Lucy      **** Steen ***"));
      restart = false;
      delay(2000);
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print(F("                Happy Christmas"));
      lcd.setCursor(0, 1);
      lcd.print(F("                **** Steen ***"));
    }
  }
  else if (step <= 16)
  {
    lcd.scrollDisplayLeft();
  }
  else if (step <= 24)
  {
    if (step % 2 == 0)
    {
      lcd.setCursor(16, 1);
      lcd.print(F("     Steen    "));
    }
    else
    {
      lcd.setCursor(16, 1);
      lcd.print(F("**** Steen ***"));
    }
  }
  else
    restart = true;

  if (restart)
  {
    lcd.home();
    step = 0;
  }
  else
    step++;

  delay(500); //ms
}

