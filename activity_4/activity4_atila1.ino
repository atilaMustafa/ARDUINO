
  int tilt = 12;
  int led1 = 2;
  int led2= 3;
  int led3= 4;
  int led4= 5;
  int piezo=9;
  int ldr = A0;
void setup()
{

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(piezo,OUTPUT);
  pinMode(tilt,INPUT);
 
  
  

} 

void loop() 
{

  int digitalval=digitalRead(tilt);
  int deger= analogRead(ldr);
 if(deger>500 &&  digitalval== 1)
 {
  for(int a=2;a>6;a++)
  { 
  digitalWrite(a,HIGH);
  delay(deger);
  digitalWrite(a,LOW);
  
  }
  
  }
  else if (deger>500 && digitalval== LOW ){
    
    int atilafreq[]= {523,554,587,622,659,698,740,784,831,880,932,988,1047};
  int i;
   for(i=0;i<13;i++)
   {
     tone(9, atilafreq[i],200);
     delay(deger);
   }
  delay(deger);
   for(i=12;i>-1;i--)
   {
     tone(9, atilafreq[i],200);
     delay(deger);
    
    
    
    
    
     }


  
   }
}