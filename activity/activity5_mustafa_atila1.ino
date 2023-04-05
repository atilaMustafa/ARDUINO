int tiltPin = 2;
int buzzer = 12; //the pin of the active buzzer
int blue=3;
int green=5;
int red=6;
int digitalVal=HIGH;
int ts=0;
int ab=0;
int pr=0;
int led=0;
int lightPin = 0;
char ch;
int delayres = 0 ;
int tiltval=0;
int C5 = 523;
int D = 587;
int E = 659;
int F = 698;
int G = 784;
int A = 880;
int B = 988;
int C6 = 1047;

int notalar[] = {C5, D, E, F, G, A, B, C6};

void abSwitch()
{
  if (ab == 1)
  {
    ab = 0;
    Serial.println("Active Buzzer has been turned off.");
  }
  else
  {
    ab = 1;
    Serial.println("Active Buzzer has been turned on.");
  }
}

void prSwitch()
{
  if (pr == 1)
  {
    pr = 0;
    Serial.println("Photoresistor has been turned off.");
  }
  else
  {
    pr = 1;
    Serial.println("Photoresistor has been turned on.");
  }
  
}

void tsSwitch()
{
  if (ts == 1)
  {
    ts = 0;
    Serial.println("Tilt Switch has been turned off.");
  }
  else
  {
    ts = 1;
    Serial.println("Tilt Switch has been turned on.");
  }
}

void tiltPrint()
{
  int temp=digitalVal;
  digitalVal = digitalRead(tiltPin);
  if (temp != digitalVal)
  {
    Serial.print("Tilt Switch orientation has changed, new orientation is ");
    if (digitalVal == HIGH) Serial.println("UP");
    else Serial.println("DOWN");
  }
}

void buzz()
{
  int i;
  for(i=0;i<100;i++)
  {
    digitalWrite(buzzer,HIGH);
    delay(1); //wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(1); //wait for 1ms
  }
}
void ledsOn()
{
  Serial.println("All LEDs on");
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
  delay(200);
}
void ledsOff()
{
  Serial.println("All LEDs off");
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
  delay(200);
}
void rgbledOn()
{
  led = ch - '0';
  Serial.print("Turned on LED ");
  Serial.println(led);
 
  // enter here methodology to turn the RGB LED on to the predetermined color for a while and then turn it off.
if (ch=='2')
{
 analogWrite(red,0);
 analogWrite(green,0);
 analogWrite(blue,255);
  Serial.println("blue led on.");
  if (tiltval==LOW)
  {tone(buzzer,D);
   delay(delayres);
  }
}
else if (ch=='1')
{
 analogWrite(red,255);
 analogWrite(green,0);
 analogWrite(blue,0);
  Serial.println("red led on.");
  if (tiltval==LOW)
  {tone(buzzer,C5);
   delay(delayres);
  }
}
else if (ch=='3')
{
 analogWrite(red,0);
 analogWrite(green,255);
 analogWrite(blue,0);
  Serial.println("green led on.");
  if (tiltval==LOW)
  {tone(buzzer,E);
   delay(delayres);
  }
}
else if (ch=='4')
{
 analogWrite(red,255);
 analogWrite(green,255);
 analogWrite(blue,0);
  Serial.println("yellow led on.");
  if (tiltval==LOW)
  {tone(buzzer,F);
   delay(delayres);
  }
  
}
else if (ch=='5')
{
 analogWrite(red,0);
 analogWrite(green,255);
 analogWrite(blue,255);
  Serial.println("cyan led on.");
  if (tiltval==LOW)
  {tone(buzzer,G);
   delay(delayres);
  }
}  
 else if (ch=='6')
{
 analogWrite(red,139);
 analogWrite(green,0);
 analogWrite(blue,139);
   Serial.println("magenta led on.");
   if (tiltval==LOW)
  {tone(buzzer,A);
   delay(delayres);
  }
} 
  else if (ch=='7')
{
 analogWrite(red,153);
 analogWrite(green,102);
 analogWrite(blue,51);
    Serial.println("brown led on.");
    if (tiltval==LOW)
  {tone(buzzer,B);
   delay(delayres);
  }
}
  else if (ch=='8')
{
 analogWrite(red,255);
 analogWrite(green,170);
 analogWrite(blue,170);
    Serial.println("pink led on.");
    if (tiltval== LOW)
  {tone(buzzer,C6);
   delay(delayres);
  }
}
}

void prPrint()
{
  int reading  = analogRead(lightPin);
  int light = reading / 50;  // change this number "50" to other values to see the effect
  Serial.print("Incoming light amount is ");
  Serial.println(light);
  delay(500); // delaying for a little while so that the photoresistor input is not printed all the time
              // but instead it is printed only twice a second
}
void getChar()
{
  ch = Serial.read();
  if (ch >= '1' && ch <= '8') rgbledOn();
  else if (ch == 'a') abSwitch();
  else if (ch == 'p') prSwitch();
  else if (ch == 't') tsSwitch();
  else if (ch == 'v') ledsOn();
  else if (ch == 'x') ledsOff();
}
void setup() 
{
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
  pinMode(tiltPin,INPUT);
  digitalWrite(tiltPin, HIGH);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready
  delay(200);
  Serial.println("Enter LED Number 1 to 8, 'a', 'p', 't', 'v', or 'x'");
  
  
}

void loop() 
{
  tiltval = digitalRead(2);
  //Serial.println(tiltval);
  delayres=analogRead(lightPin);
  //Serial.println(delayres);
  if (Serial.available()) getChar();
  if (ts == 1) tiltPrint();
  if (ab == 1) buzz();
  if (pr == 1) prPrint();
  // nota satırı
  // 1 4 3 8 3 4 5 6 7 8 6 2 3 4 5 6 6 5 4 3 2 3 3 4 3 2 1 2 3 4 5 6 7 8 5 4 3 2 1 2 3
}