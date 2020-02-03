#include <string.h>
int Red = 11;
int Green = 10;
int Blue = 9;
int R = 0;
int G = 0;
int B = 0;
String col;

void setup(){
  Serial.begin(9600);  
}

void loop() {
  if(Serial.available()){
    col = Serial.readString();
    }
  if(col == "getcol"){
    String getcol = "r" + String(R) + " g" + String(G) + " b" + String(B);
    Serial.println(getcol);
    col = "";
    }
  else if(col[0] == 'R'||col[0] == 'r'){
    if(num(col).toInt()<=255)
      R = num(col).toInt();
  }
  else if(col[0] == 'G'||col[0] == 'g'){
    if(num(col).toInt()<=255)
      G = num(col).toInt();
    }
  else if(col[0] == 'B'||col[0] == 'b'){
    if(num(col).toInt()<=255)
      B = num(col).toInt();
    }
  else if(col == "off"){R=0;G=0;B=0;}
  
  analogWrite(Red, R);
  analogWrite(Green, G);
  analogWrite(Blue, B);
}
String num(String s){
  for(int i = 0;i<s.length();i++)
  s[i]= s[i+1];
  return s;
  }
