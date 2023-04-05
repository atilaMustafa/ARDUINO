int a1 = 4; 
int a2 = 5; 
int a3 = 6; 
int a4 = 7; 


int b1 = 8; 
int b2 = 9; 
int b3 = 10; 
int b4 = 11; 
//&&
int n=0; 
int d1;
int d2;
int button = 2;
int state = 0;
int a = 0;
int durum_dongu;
int sayac;
int buzzer = 13;
int ledR = A3;
int ledB = A4;
int ledG = A5;


void setup()
{
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(button,INPUT);
Serial.begin(9600);

  
}

void loop()
{
  String gelen;
  if (Serial.available() > 0) { 
    gelen = Serial.readString();
    n = gelen.toInt();
    
  }
  
durum_dongu = digitalRead(2);
 
 while(durum_dongu == true )
{
   durum_dongu = digitalRead(2);
   
   Serial.println(durum_dongu);

 if(durum_dongu == true )
 {
      sayac++;
   Serial.print("sayac = ");
   Serial.println(sayac);
      delay(500);
 }

  if (sayac == 3)
  {
    sayac = 0;
  }
  else if (sayac == -1)
  {
    sayac = 2;
  }
}
   switch(sayac)
 {
  case 0:
     Serial.println("Sistem aktif değil");
     Serial.println(n);
     analogWrite(ledR,0);
     analogWrite(ledG,0);
     analogWrite(ledB,0);

     if(durum_dongu == true )
 {
      sayac++;
   Serial.print("sayac = ");
   Serial.println(sayac);
      delay(500);
 }

     break;
     
  case 1:
  
 n++;
 Serial.println("ileri sayim modu aktif");
 d1=n%10; 
 d2=n/10; 
 disp1(d1);
 disp2(d2);
 delay(1000);  
    if(n==99)
 {
   //1
   tone(buzzer,1000,1000);
      analogWrite(ledR,255);
      delay(1000);
      analogWrite(ledR,0);
      tone(buzzer,300,1000);

      analogWrite(ledB,255);
      delay(1000);
      analogWrite(ledB,0);
      tone(buzzer,1000,1000);

      analogWrite(ledR,255);
      delay(1000);
      analogWrite(ledR,0);
      tone(buzzer,300,1000);
   
      analogWrite(ledB,255);
      delay(1000);
      analogWrite(ledB,0);
      tone(buzzer,1000,1000);
      
     
      n=0; 
      
      analogWrite(ledR,0);
      analogWrite(ledG,0);
      analogWrite(ledB,0);
      sayac = 0;
      
 }
  
  break;
 //1
 case 2:
 Serial.println("geri sayim modu aktif");
 n--;
 d1=n%10; 
 d2=n/10; 
 disp1(d1);
 disp2(d2);
 delay(500); 
     if(n==-1)
 {
tone(buzzer,500,2000);
      analogWrite(ledR,255);
      delay(1000);
      analogWrite(ledR,0);
      
      analogWrite(ledG,255);
      delay(1000);
      analogWrite(ledG,0);
      
      analogWrite(ledB,255);
      delay(1000);
      analogWrite(ledB,0);
      
      analogWrite(ledR,255);
      delay(1000);
      analogWrite(ledR,0);
      
      analogWrite(ledG,255);
      delay(1000);
      analogWrite(ledG,0);
      
      analogWrite(ledB,255);
      delay(1000);
      analogWrite(ledB,0);

      n=0; 
      
      analogWrite(ledR,0);
      analogWrite(ledG,0);
      analogWrite(ledB,0);
      sayac = 0;
 } 
  break;
 
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
  if(num == 1)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 2)
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 3)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, LOW);
    digitalWrite(a4, LOW);
  }
  if(num == 4)
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 5)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 6)
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 7) 
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, HIGH);
    digitalWrite(a3, HIGH);
    digitalWrite(a4, LOW);
  }
  if(num == 8) 
  {
    digitalWrite(a1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, HIGH);
  }
  if(num == 9)
  {
    digitalWrite(a1, HIGH);
    digitalWrite(a2, LOW);
    digitalWrite(a3, LOW);
    digitalWrite(a4, HIGH);
  }
}

void disp2(int num)
{
  if(num == 0)
  {
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
    digitalWrite(b4, LOW);
  }
  if(num == 1)
  {
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
    digitalWrite(b4, LOW);
  }
  if(num == 2)
  {
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, LOW);
    digitalWrite(b4, LOW);
  }
  if(num == 3)
  {
    digitalWrite(b1, HIGH);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, LOW);
    digitalWrite(b4, LOW);
  }
  if(num == 4)
  {
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(b3, HIGH);
    digitalWrite(b4, LOW);
  }
  if(num == 5) 
  {
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(b3, HIGH);
    digitalWrite(b4, LOW);
  }
  if(num == 6) 
  {
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, HIGH);
    digitalWrite(b4, LOW);
  }
  if(num == 7) 
  {
    digitalWrite(b1, HIGH);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, HIGH);
    digitalWrite(b4, LOW);
  }
  if(num == 8) 
  {
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
    digitalWrite(b4, HIGH);
  }
  if(num == 9)
  {
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
    digitalWrite(b4, HIGH);
  }
}