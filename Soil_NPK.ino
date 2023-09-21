#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
 
//#define SCREEN_WIDTH 128    // OLED display width, in pixels
//#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET); 
 
#define RE 8
#define DE 7
 
//const byte code[]= {0x01, 0x03, 0x00, 0x1e, 0x00, 0x03, 0x65, 0xCD};
const byte nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};
 
byte values[11];
SoftwareSerial mod(0,1); //Ro=0 IE=1
 
void setup() {
  Serial.begin(9600);
   // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  mod.begin(9600);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  display.clearDisplay();
  display.setCursor(25, 15);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println(" NPK Sensor");
  display.setCursor(25, 35);
  display.setTextSize(1);
  display.print("Initializing");
  display.display();
  delay(3000);
  // put RS-485 into receive mode
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
}
 
void loop() {
  byte val1,val2,val3;
  val1 = nitrogen();
  delay(250);
  val2 = phosphorous();
  delay(250);
  val3 = potassium();
  delay(250);
  
  
  Serial.print("Nitrogen: ");
  Serial.print(val1);
  Serial.println(" mg/kg");
  Serial.print("Phosphorous: ");
  Serial.print(val2);
  Serial.println(" mg/kg");
  Serial.print("Potassium: ");
  Serial.print(val3);
  Serial.println(" mg/kg");
  delay(2000);
 
  display.clearDisplay();
  
 
  display.setTextSize(2);
  display.setCursor(0, 5);
  display.print("N: ");
  display.print(val1);
  display.setTextSize(1);
  display.print(" mg/kg");
 
  display.setTextSize(2);
  display.setCursor(0, 25);
  display.print("P: ");
  display.print(val2);
  display.setTextSize(1);
  display.print(" mg/kg");
 
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print("K: ");
  display.print(val3);
  display.setTextSize(1);
  display.print(" mg/kg");
 
  display.display();
}
 
byte nitrogen(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(nitro,sizeof(nitro))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}
 
byte phosphorous(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(phos,sizeof(phos))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}
 
byte potassium(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(pota,sizeof(pota))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}
