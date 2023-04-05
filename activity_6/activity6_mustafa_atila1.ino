int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int latchPin2 = 7;
int clockPin2 = 8;
int dataPin2 = 6;
int ledPin = 5;
int sayac = 0;
int b1 = 1;
int b2 = 2;
int b3 = 3;
int b4 = 4;
int flag = 0;
byte leds = 0;
byte display1 = 0;
byte ledarray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111, B10000001, B11000011, B11100111, B11111111,B00000001,B00000010,B00000100,B00001000,B00010000,B00100000,B01000000,B10000000};
byte displayARRAY[] = {B00000000, B00111111, B00000110, B01011011, B01001111, B01100110, B01101101, B01111101, B00000111, B01111111, B01101111}; // OFF / 0-9

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin,  OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  display1 = displayARRAY[1];
  registeraYaz2();
  Serial.begin(9600);
}

void loop()
{
  updateFlag();
  while (flag == 1)
  {
    updateFlag();
    if (flag != 1) {
      break;
    }
    exeb1();
  }
  while (flag == 2)
  {
    updateFlag();
    if (flag != 2) {
      break;
    }
    exeb2();

  }
  while (flag == 3)
  {
    updateFlag();
    if (flag != 3) {
      break;
    }
    exeb3();

  }
  while (flag == 4)
  {
    updateFlag();
    if (flag != 4) {
      break;
    }
    exeb4();

  }



}
void exeb1() { 

  for (int i = 0; i <= 8; i++)
  {
    updateFlag();
    if (flag != 1) {break;}
    leds = ledarray[i];
    display1 = displayARRAY[i + 1];
    registeraYaz();
    registeraYaz2();
    for (int i = 0; i < 500; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 1) {
        break;
      }

    }
  }
  for (int i = 8; i >= 0; i--)
  {
    updateFlag();
    if (flag != 1) {
      break;
    }
    leds = ledarray[i];
    display1 = displayARRAY[i + 1];
    registeraYaz();
    registeraYaz2();
    for (int i = 0; i < 500; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 1) {
        break;
      }

    }
  }
}

void exeb2() { 
  for (int i = 9; i <= 12; i++)
  {
    updateFlag();
    if (flag != 2) {
      break;
    }
    leds = ledarray[i];
    registeraYaz();
    for (int i = 0; i < 350; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 2) {
        break;
      }

    }
  }
  sayac1();
  for (int i = 11; i >= 9; i--)
  {
    updateFlag();
    if (flag != 2) {
      break;
    }
    leds = ledarray[i];
    registeraYaz();
    delay(350);
    for (int i = 0; i < 350; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 2) {
        break;
      }

    }
  }
  sayac1();

}
void exeb3() {
  leds = 0;
  registeraYaz();
  for (int a = 10; a > 0; a--)
  {
    display1 = displayARRAY[a];
    registeraYaz2();
    for (int d = 0; d <= 1000; d++) {
      delay(1);
      updateFlag();
      if (flag != 3) {
        break;
      }
    }
  }
  for (int e = 1; e < 4; e++)
  {
    display1 = displayARRAY[1];
    registeraYaz2();
    for (int i = 0; i < 500; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 3) {
        break;
      }
    }
    display1 = displayARRAY[0];
    registeraYaz2();
    for (int i = 0; i < 500; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 3) {
        break;
      }
    }
  }

  for (int x = 13;x<=20;x++)
  { 
    leds = ledarray[x];
    registeraYaz();
    for (int i = 0; i < 100; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 3) {
        break;
      }
    }
       
    }

  for (int x = 20;x >=13;x--)
  { 
    leds = ledarray[x];
    registeraYaz();
    for (int i = 0; i < 100; i++)
    {
      delay(1);
      updateFlag();
      if (flag != 3) {
        break;
      }
    }
       
    }
  
}
void exeb4() {

  leds = 0;
  display1 = displayARRAY[1];
  registeraYaz();
  registeraYaz2();
  updateFlag();
  
}
void updateFlag()
{
  if (digitalRead(b1) == LOW) flag = 1;
  if (digitalRead(b2) == LOW) flag = 2;
  if (digitalRead(b3) == LOW) flag = 3;
  if (digitalRead(b4) == LOW) flag = 4;

}

void registeraYaz()
{
 
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
void registeraYaz2()
{
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin2, clockPin2, LSBFIRST, display1);
  digitalWrite(latchPin2, HIGH);
}
void sayac1() {

  if (sayac == 10) {
    display1 = displayARRAY[1];
    registeraYaz2();
    sayac = 0;

  }
  if (sayac < 10 && sayac > -1) {
    sayac++;
    display1 = displayARRAY[sayac];
    registeraYaz2();
  }
}