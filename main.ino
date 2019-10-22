
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2); // initializes the LCD

  // VAR //
const int IN_D0 = 8; // digital input
const int IN_D1 = 7;
const int IN_D2 = 6;
const int IN_D3 = 5;
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int sum = 0;
int mny = 0;




void setup() {
  pinMode(IN_D0, INPUT);
  pinMode(IN_D1, INPUT);
  pinMode(IN_D2, INPUT);
  pinMode(IN_D3, INPUT);

  
  Serial.begin(9600);
  
  lcd.begin(); // begins connection to the LCD module
  lcd.backlight(); // turns on the backlight
}

  // VAR 2 //
bool value_D0;
bool value_D1;
bool value_D2;
bool value_D3;

void loop() {
  value_D0 = digitalRead(IN_D0); // reads the digital input from the IR distance sensor  
  value_D1 = digitalRead(IN_D1);
  value_D2 = digitalRead(IN_D2);
  value_D3 = digitalRead(IN_D3);

  // SET LCD //
  lcd.setCursor(0, 0);
  lcd.print("10:");
  lcd.setCursor(0, 1);
  lcd.print("5 :");
  lcd.setCursor(6, 0);
  lcd.print("2:");
  lcd.setCursor(6, 1);
  lcd.print("1:");
  lcd.setCursor(11, 0);
  lcd.print("SM");  
  lcd.setCursor(11, 1);
  lcd.print("MN");

  // some code to detect coin //
  if (value_D0 == false) {
    n1 = n1 + 1;
    delay(100);
  };
  if (value_D1 == false) {
    n2 = n2 + 1;
    delay(100);
  };
  if (value_D2 == false) {
    n3 = n3 + 1;
    delay(100);
  };
  if (value_D3 == false) {
    n4 = n4 + 1;
    delay(100);
  };
  


  // Add all coin up to display //
  sum = n1 + n2 + n3 + n4;
  mny = (n1 * 10) + (n2 * 5) + (n3 * 2) + (n4 * 1);
  
  // Set the display //
  lcd.setCursor(3, 0);
  lcd.print(n1);
  lcd.setCursor(3, 1);
  lcd.print(n2);
  lcd.setCursor(8, 0);
  lcd.print(n3);
  lcd.setCursor(8, 1);
  lcd.print(n4);
  lcd.setCursor(13, 0);
  lcd.print(sum);  
  lcd.setCursor(13, 1);
  lcd.print(mny);

  Serial.println(value_D0);
  

}



  

