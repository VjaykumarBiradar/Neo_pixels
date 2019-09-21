#include <Adafruit_NeoPixel.h>

#define PIN 6
#define inPin 2
#define outPin 3
#define o 4
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(550, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel. Avoid connecting
// on a live circuit... if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show(); // initialize all pixels to "off"
  strip.setBrightness(255);
  pinMode(outPin, OUTPUT);
  pinMode(inPin, INPUT_PULLUP);
  digitalWrite(outPin, HIGH);
   pinMode(o, OUTPUT);
}


void loop() {
//  for (int i = strip.numPixels(); i >= 0; i--) {
//    strip.setPixelColor(i, 0, 0, 0);
//    strip.show();
//   // delay(1);
//  }
if (digitalRead(inPin)==LOW) 
{
  strip.clear();
  
  //delay(3000);
  colorwipe();
  digitalWrite(outPin, LOW);
 digitalWrite(o, LOW);
  delay(500);
 digitalWrite(outPin, HIGH);
 digitalWrite(o, HIGH);
  //brighten();
  darken();
}

}
void colorwipe() {

  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    delay(20);
  }

}
// 0 to 255
//void brighten() {
//  uint16_t i, j;
//
//  for (j = 45; j < 255; j++) {
//    for (i = 0; i < strip.numPixels(); i++) {
//      strip.setPixelColor(i, 0, 0, j);
//    }
//    strip.show();
//    delay(5);
//  }
//  //delay(1500);
//}

// 255 to 0
void darken() {
  Serial.begin(9600);
  uint16_t i, j;

  for (j = 255; j > 45; j--) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 0, j);
    }
    strip.show();
    delay(5);
    Serial.println(j);

  }
  delay(1500);


}
