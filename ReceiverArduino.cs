#include<Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  lcd.begin(16, 2);
  lcd.print("Starting");
}

void loop() {
  delay(100);
}
void receiveEvent(int howMany){
  int x=1,y=0;
  lcd.clear();
  lcd.setCursor(0,1);
  while(Wire.available()){
   x=Wire.read();
   y=Wire.read();
  }
  if(x==1){
    lcd.print("Safe");
  }
  else if(y==1){
    lcd.print("Danger");
  }
}