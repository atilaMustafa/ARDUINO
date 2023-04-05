int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 9;
int led8 = 10;
int led9 = 11;
int led10 = 12;
int ldr1 = A0;
int ldr2 = A1;
int tiltPin = 8;
int buzzer= 13;
int LEDs[]= {led1,led2,led3,led4,led5,led6,led7, led8, led9,led10};
int tiltVal= 0;
int ldr1_deger = 0;
int ldr2_deger = 0;


void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(buzzer, OUTPUT);
   
  pinMode(tiltPin,INPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  digitalWrite(tiltPin, HIGH);
  Serial.begin(9600);
  
}

void loop()
{

  int ldr1_deger = analogRead(ldr1)+42;
  int ldr2_deger= analogRead(ldr2)+42;
  int tiltVal = digitalRead(tiltPin);
  Serial.print("ldr1_deger : ");
  Serial.println(ldr1_deger);
  Serial.print("ldr2_deger : ");
  Serial.println(ldr2_deger);
  
   if(tiltVal == HIGH){
     Serial.println("Durum1 e girildi");
     

      if (ldr1_deger <300){
        Serial.println("10 led Yanıyor");
        
       for(int i=0; i<10; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }   
     
     else if (ldr1_deger <360){
       Serial.println("9 led Yanıyor");
       for(int i=0; i<9; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }  
     
      else if (ldr1_deger <400){
        Serial.println("8 led Yanıyor");
       for(int i=0; i<8; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }     
      else if (ldr1_deger <460){
        Serial.println("7 led Yanıyor");
       for(int i=0; i<7; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }         
      else if (ldr1_deger <500){
        Serial.println("6 led Yanıyor");
       for(int i=0; i<6; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      } 
      else if (ldr1_deger <560){
        Serial.println("5 led Yanıyor");
       for(int i=0; i<5; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }
      else if (ldr1_deger <600){
        Serial.println("4 led Yanıyor");
       for(int i=0; i<4; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }
      else if (ldr1_deger <660){
        Serial.println("3 led Yanıyor");
       for(int i=0; i<3; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }
     
      else if (ldr1_deger <700){
        Serial.println("2 led Yanıyor");
       for(int i=0; i<2; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }
      else if (ldr1_deger <790){
        Serial.println("1 led Yanıyor");
       for(int i=0; i<1; i++){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr2_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr2_deger);
        tone(buzzer,ldr1_deger,ldr2_deger);
       }      
      }
     
   }
  
   else{
      Serial.println("Durum 2 ye girildi...");
      if (ldr2_deger <300){
        Serial.println("10 led Yanıyor");
       for(int i =10 ; i >= 0; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }     
      else if (ldr2_deger <360){
        Serial.println("9 led Yanıyor");
       for(int i =10 ; i >= 1; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }         
      else if (ldr2_deger <400){
        Serial.println("8 led Yanıyor");
       for(int i =10 ; i >= 2; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      } 
      else if (ldr2_deger <460){
        Serial.println("7 led Yanıyor");
       for(int i =10 ; i >= 3; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }
      else if (ldr2_deger <500){
        Serial.println("6 led Yanıyor");
       for(int i =10 ; i >= 4; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }
      else if (ldr2_deger <560){
        Serial.println("5 led Yanıyor");
       for(int i =10 ; i >= 5; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }
      else if (ldr2_deger <600){
        Serial.println("4 led Yanıyor");
       for(int i =10 ; i >= 6; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }
      else if (ldr2_deger <660){
        Serial.println("3 led Yanıyor");
       for(int i =10 ; i >= 7; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }
      else if (ldr2_deger <700){
        Serial.println("2 led Yanıyor");
       for(int i =10 ; i >= 8; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }
      else if (ldr2_deger <750){
        Serial.println("1 led Yanıyor");
       for(int i =10 ; i >= 9; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }
      else if (ldr2_deger <790){
        Serial.println("0 led Yanıyor");
       for(int i =10 ; i >= 10; i--){
        digitalWrite(LEDs[i], HIGH);
        delay(ldr1_deger);
        digitalWrite(LEDs[i], LOW);
        delay(ldr1_deger);
        tone(buzzer,ldr2_deger,ldr1_deger);
       }      
      }

   }
}
