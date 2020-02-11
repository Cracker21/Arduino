#include <Servo.h>
#include "Ultrasonic.h"     //robocraft.ru/files/sensors/Ultrasonic/HC-SR04/ultrasonic-HC-SR04.zip
Servo myservo;
int cm, duration;
int pos = 0;
int Echo = 7;
int Trig = 8;
int mode = 0;
void setup() {
  Serial.begin(9600);
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object
  pinMode(Echo, INPUT);   
  pinMode(Trig, OUTPUT);
  pinMode(13,OUTPUT);   //left motors forward
  pinMode(12,OUTPUT);   //left motors reverse
  pinMode(11,OUTPUT);   //right motors forward
  pinMode(10,OUTPUT);   //right motors reverse

}

void loop() {
            if(Serial.available()){
              int ch = Serial.readString().toInt();
              if(ch == 1||ch == 0)mode = ch;
            }
  //turn servo left
  if(mode == 1){
    for(pos = 50;pos<=130;pos+=2){
      cycle();
      myservo.write(pos); 
    }
  }else if(mode == 0){        
        Stop();
  }
            if(Serial.available()){
              int ch = Serial.readString().toInt();
              if(ch == 1||ch == 0)mode = ch;
            }
  // turn servo right
  if(mode == 1){
    for(pos = 130;pos>=50;pos-=2){
      cycle();
      myservo.write(pos); 
    }
  }else if(mode == 0){        
        Stop();
  }
}
void Stop() {
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
  }
void cycle() {
    digitalWrite(Trig, LOW);
    delayMicroseconds(5);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);            // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
    digitalWrite(Trig, LOW);
    duration = pulseIn(Echo, HIGH);   //  Время задержки акустического сигнала на эхолокаторе.
    cm = (duration / 2) / 29.1;       // Теперь осталось преобразовать время в расстояние
    //delay(50);
    if(cm <= 20){               //backward
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(13, LOW);
        digitalWrite(12, HIGH);
      }else if(cm <= 50){             //turn right
        digitalWrite(12, LOW);    
        digitalWrite(11, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(13, HIGH);
      }else{                          //toward
        digitalWrite(12, LOW);
        digitalWrite(10, LOW);
        digitalWrite(13, HIGH);
        digitalWrite(11, HIGH);
        }
  }
