const int sensor_pin= A0;
 int sensor_deger = 0;
 float voltaj_deger= 0;
 float sicaklik= 0;

void setup() {
 Serial.begin(9600);
}

void loop() {
  sensor_deger= analogRead(sensor_pin);
  Serial.print("okunan deger= ");
  Serial.println(sensor_deger);
  voltaj_deger= (sensor_deger/1023.0)*5000;
  Serial.print("V_deger= ");
  Serial.println(voltaj_deger);
  sicaklik=voltaj_deger/10.0;
  Serial.print("sicaklik= ");
  Serial.println(sicaklik);
  delay(350);
  
}
