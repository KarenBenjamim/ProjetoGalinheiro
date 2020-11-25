//--------LCD------------
#include <Arduino.h>
#include <LiquidCrystal.h> // biblioteca Liquid Crystal
LiquidCrystal lcd(16, 17, 5, 18, 19, 21); // pinos do LCD - RS E D4 D5 D6 D7

//-------LDR--------

#define portaLDR 33
#define ledLDR 26 // define pino digital D13
int Leitura = 0; // variavel inteiro igual a zero
float VoltageLDR; // variavel numero fracionario
float ResLDR; // variavel numero fracionario

//--------DHT11----------
#include <Adafruit_Sensor.h> // Biblioteca DHT Sensor Adafruit4
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT11 // Sensor DHT11
#define DHTPIN 27 // Pino do Arduino no Sensor (Data)
#define ledHDT 14 //led no pino 11
DHT_Unified dht(DHTPIN, DHTTYPE);// configurando o Sensor DHT - pino e tipo
uint32_t delayMS = 500; // variável para atraso no tempo
float temp = 0;
float umi = 0;

#define PinButton 35
//----------SETUP------
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // monitor serial 9600 bps
  dht.begin(); // inicializa a função
  sensor_t sensor;
  lcd.begin(16, 2); // inicializa LCD 16x2
  pinMode(ledLDR, OUTPUT);
  pinMode(ledHDT, OUTPUT); 
  delay(500); // atraso de 0,5 segundos
  pinMode(PinButton, INPUT);
}

//-------LOOP---------
void loop() {
  // put your main code here, to run repeatedly:
  DHT();
  LDR();
  LCD();
}
