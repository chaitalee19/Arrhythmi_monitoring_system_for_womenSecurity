#include <Wire.h>
int push1=2;
int push2=3;
int p=8;
int danger=0;
int c=0;
int r=5;
int g=4;
void setup()
{
  Wire.begin();
  pinMode(push1, INPUT);
  pinMode(push2, INPUT);
  pinMode(p,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int a=1,b=0;
  Wire.beginTransmission(4);
  int x = digitalRead(push1);
  int y = digitalRead(push2);
  if(y==1){
    danger=1;
    c=0;
  }
  if(x==1){
    c++;
    delay(200);
  }  
  if(c==2){
    danger=0;
    c=0;
  }
  if(danger){
    tone(p,1000,200);
    digitalWrite(r,HIGH);
    digitalWrite(g,LOW);
    a=0;
    b=1;
  }
  else{
    //tone(p,0,0);
    digitalWrite(g,HIGH);
    digitalWrite(r,LOW);
    a=1;
    b=0;
  }
  
  Serial.println(c);
  Wire.write(a);
  Wire.write(b);
  Wire.endTransmission();
  delay(100);
}