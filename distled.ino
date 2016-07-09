#include <WS2812.h>

WS2812 LED1(1); 
WS2812 LED2(1); 
WS2812 LED3(1); 
WS2812 LED4(1); 

cRGB value;
cRGB value2;
cRGB value3;
cRGB value4;

int ton = 12;
int trig = 8;
int echo = 9;

void setup() {
  
  Serial.begin(9600);
  pinMode(ton,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
	LED1.setOutput(2); // Digital Pin 2
  LED2.setOutput(4); // Digital Pin 4
  LED3.setOutput(5); // Digital Pin 5
  LED4.setOutput(6); // Digital Pin 6

  value.b = 0; value.g = 255; value.r = 0; // RGB
  LED1.set_crgb_at(0, value); // Set value at LED found at index 0
  value2.b = 0; value2.g = 255; value2.r = ; // RGB
  LED2.set_crgb_at(0, value2); // Set value at LED found at index 0
  value3.b = 0; value3.g = 255; value3.r = 0; // RGB
  LED3.set_crgb_at(0, value3); // Set value at LED found at index 0
  value4.b = 0; value4.g = 255; value4.r = 0; // RGB
  LED4.set_crgb_at(0, value4); // Set value at LED found at index 0
}

void loop() {
  int dist = 0;
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  dist = pulseIn(echo,HIGH) / 58.2;
  Serial.print(dist);
  Serial.println("cm");
  delay(200);

  if ( dist < 50 )
  {
     digitalWrite(ton,HIGH);
     delay(100);
     digitalWrite(ton,LOW);
     
     value.b = 255; value.g = 255; value.r = 255;
     value2.g = 255; value2.b = 255; value2.r = 255;
     value3.g = 255; value3.b = 255; value3.r = 255;
     value4.g = 255; value4.b = 255; value4.r = 255;
     LED1.set_crgb_at(0, value); // Set value at LED found at index 0
     LED1.sync();
     LED2.set_crgb_at(0, value2); // Set value at LED found at index 0
     LED2.sync();
     LED3.set_crgb_at(0, value3); // Set value at LED found at index 0
     LED3.sync();
     LED4.set_crgb_at(0, value4); // Set value at LED found at index 0
     LED4.sync();
     
     delay(150);
  }
  value.b = 0; value.g = 255; value.r = 0; // RGB
  LED1.set_crgb_at(0, value); // Set value at LED found at index 0
  value2.b = 0; value2.g = 255; value2.r = ; // RGB
  LED2.set_crgb_at(0, value2); // Set value at LED found at index 0
  value3.b = 0; value3.g = 255; value3.r = 0; // RGB
  LED3.set_crgb_at(0, value3); // Set value at LED found at index 0
  value4.b = 0; value4.g = 255; value4.r = 0; // RGB
  LED4.set_crgb_at(0, value4); // Set value at LED found at index 0
}

