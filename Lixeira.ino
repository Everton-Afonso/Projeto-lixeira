#include <Servo.h> 

#define trig 6 
#define echo 7

long  duracao, distancia;

Servo motor;  //iniciando o Servo motor

void setup ()
{
  Serial.begin (9600);
  motor.attach(8);  //definindo o pino 8 para o motor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop ()
{
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  pinMode(echo, INPUT); //caso não der certo retira este 
  duracao = pulseIn(echo, HIGH);
  distancia = (duracao / 2) / 29.1;
  if(distancia < 20)
  {
    motor.write(90);
    delay(1500);
  }else
  {
    motor.write(0);
  }
delay(500);
}
