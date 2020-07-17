#include <Servo.h>

Servo servoMotor;
int triger = 5;
int echo = 7;

void setup() {
  
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  servoMotor.attach(9);
  Serial.begin(9600);  
}
void loop() {
  
  digitalWrite(triger, LOW);
  delayMicroseconds(2);

  digitalWrite(triger, HIGH);
  delayMicroseconds(10);

  float tiempo=pulseIn(echo,HIGH);
  float distancia = (tiempo/2)/29.1;
  
  Serial.print(distancia);
  Serial.println("cm");
  delay(500);
  
  if (distancia < 20){
    servoMotor.write(140);
    delay(500);
  }else if (distancia > 50){
    servoMotor.write(0);
    delay(500);
    }
}
