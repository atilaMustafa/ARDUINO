#include <util/atomic.h> 
#include<Wire.h>
#define ENCA 2 // YELLOW
#define ENCB 3 // WHITE

#define IN2 6
#define IN1 7



volatile int posi = 0; 
long prevT = 0;
float eprev = 0;
float eintegral = 0;
float turn; 
int a1 = 8; 
int a2 = 9; 
int a3 = 10; 
int a4 = 11; 
int a5 = 4;
int led1= A2;
int led2= A3;


int x;
int n;
int d1;
int t=0;
int pos = 0; 
int target =0;

void setup() {

  Serial.begin(9600);
  pinMode(0,INPUT_PULLUP);
  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  pinMode(a5, OUTPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  Serial.println("target pos");
}

void loop() {


  
 d1=pos/290;
 disp1(d1);



  while (Serial.available()>0 ){ 
  
  turn = Serial.parseFloat();
  

    

  }
  target = turn*290;  
  if(pos>2610){
   analogWrite(led1,0);
   analogWrite(led2,255);
    digitalWrite(5,HIGH);
    digitalWrite(12,HIGH);
  }
  else if(pos<-2610){
   analogWrite(led1,255);
   analogWrite(led2,0);
    digitalWrite(5,HIGH);
    digitalWrite(12,HIGH);
  }
  else {
   analogWrite(led1,0);
   analogWrite(led2,0);
    digitalWrite(5,LOW);
    digitalWrite(12,LOW);
  }
  
  if(pos<0){
   digitalWrite(a5, HIGH);  
  }
  else if (pos>0){
  digitalWrite(a5, LOW);
  
  }
  
    Serial.print(" target: ");
    Serial.print(target);
    Serial.print(" turn: ");
    Serial.print(turn);
    Serial.print(" pos1: ");
    Serial.print(pos);
    Serial.print("  display no: ");
    Serial.println(d1);

 
  float kp = 1;
  float kd = 0.025;
  float ki = 0.0;

  
  long currT = micros();
  float deltaT = ((float) (currT - prevT))/( 1.0e6 );
  prevT = currT;

  
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = posi;
  }
  
 
  int e = pos - target;

 
  float dedt = (e-eprev)/(deltaT);

  
  eintegral = eintegral + e*deltaT;

  
  float u = kp*e + kd*dedt + ki*eintegral;

  


  
  int dir = 1;
  if(u<0){
    dir = -1;
  }

  
  setMotor(dir,IN1,IN2);


 
  eprev = e;


}

void setMotor(int dir, int in1, int in2){
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }  
}
void disp1(int num)
{
 
  if(num == 0)
  {
    digitalWrite(a1, LOW); 
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 1 || num == -1)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 2 || num == -2)
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 3 || num == -3)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 4 || num == -4)
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 5 || num == -5)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 6 || num == -6)
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 7 || num == -7) 
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 8 || num == -8) 
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, HIGH);
  }
  if(num == 9 || num == -9)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, HIGH);
  }
}
void readEncoder(){
  int b = digitalRead(ENCB);
  if(b > 0){
    posi++;
  }
  else{
    posi--;
  }
}