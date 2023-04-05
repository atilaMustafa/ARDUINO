
const int trigger_pin = 13;
const int echo_pin = 12;
const int buzzer = 8;
const int led1 = 4;
const int led2 = 5; 
const int led3 = 6;
const int led4 = 7;
int sure; 
int mesafe;


void setup() {
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(trigger_pin, OUTPUT);
 pinMode(echo_pin, INPUT);
 Serial.begin(9600);


}

void loop() {
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin,LOW);
  sure=pulseIn(echo_pin,HIGH);
  mesafe = (sure/2)/29;
  Serial.println(mesafe);
  if (mesafe <= 10)
  {
   digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
   digitalWrite(led4,HIGH);
   digitalWrite(buzzer,HIGH);
   delay(50);
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(led4,LOW);
   digitalWrite(buzzer,LOW);
   delay(150);
    }
    else if (mesafe<= 25)
    {
     digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
   digitalWrite(buzzer,HIGH);
   delay(50);
    digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(buzzer,LOW);
   delay(300);
      
      }
      else if (mesafe<=50)
      {
        
           digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
   digitalWrite(buzzer,HIGH);
   delay(50);
    digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(buzzer,LOW);
   delay(750);
             
        }
       else if (mesafe<= 100)
        {
   digitalWrite(led1,HIGH);  
   digitalWrite(buzzer,HIGH);
   delay(50);
   digitalWrite(led1,LOW);
   digitalWrite(buzzer,LOW);
   delay(1000);
    }
    else
    {  
   digitalWrite(led1,HIGH);  
   delay(1000);
   digitalWrite(led1,LOW);
      }




  
  
}
