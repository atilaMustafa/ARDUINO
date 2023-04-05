#define y_led 9
#define m_led 10 
#define k_led 11

#define y_pot A0
#define m_pot A1
#define k_pot A2 
#define pot_deger A3

int y_pot_deger;
int m_pot_deger;
int k_pot_deger;
int md_deger=0;


void setup() {
Serial.begin(9600);

pinMode(y_led,OUTPUT);
pinMode(m_led,OUTPUT);
pinMode(k_led,OUTPUT);


}

void loop() {
  Serial.println(md_deger);
  check_mod();
  if(md_deger==0)
  manuel_mod();
  if(md_deger==1)
  random_mod();
  if (md_deger==2)
  fade_mod();
   


}


void manuel_mod(){
  Serial.println("manuel moda girildi");
  Serial.println(md_deger);
  y_pot_deger= analogRead(y_pot);
  k_pot_deger= analogRead(k_pot);
  m_pot_deger= analogRead(m_pot);
  k_pot_deger= map (k_pot_deger, 0, 1023,0 , 255);
  m_pot_deger= map (m_pot_deger, 0, 1023,0 , 255);
  y_pot_deger= map (y_pot_deger, 0, 1023,0 , 255);

  analogWrite(y_led, y_pot_deger);
  analogWrite(k_led, k_pot_deger);
  analogWrite(m_led, m_pot_deger);
  check_mod();
}
  


void random_mod() {
  Serial.println("rabdom moda girildi");
  Serial.println(md_deger);
  
  int time_pot;
  time_pot = analogRead(y_led);
  Serial.println(time_pot);
  int a = random(0,255);
  delay(time_pot);
  int b = random (0,255);
  delay(time_pot);
  int c = random (0,255);
  delay(time_pot);
  analogWrite(y_led,a);
  analogWrite(k_led,b);
  analogWrite(m_led,c);
  check_mod();
}

void fade_mod() {
  Serial.println("fade moda girildi");
  Serial.println(md_deger);
  
  for (int i=0;i<=255;i++)
  {Serial.print("i");
  Serial.println(i);
  analogWrite(y_led,255-i);
  analogWrite(k_led,i);
  analogWrite(m_led,i);
  delay(100);
  
  if(i==254){
  i=0;}
  
    
   }
  }

void check_mod(){
  Serial.println("check moda girildi");
  Serial.println(md_deger);
  md_deger= analogRead(pot_deger);
  md_deger= map (md_deger,0,1023,0,3);
  if(md_deger==0)
  manuel_mod();
  if(md_deger==1)
  random_mod();
  if (md_deger==2)
  fade_mod();
  
  
}
