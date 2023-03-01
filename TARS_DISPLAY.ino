#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

void setup() {
  Serial.begin(9600);
  Serial.println("Made with ♡ by shissdo"); 
 
  tft.begin();

  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
  
  Serial.println(F("Benchmark                Time (microseconds)"));

  Serial.print(F("Text                     "));
  Serial.println(introText());
  delay(500);
  jamsText();
  delay(500);


  Serial.println(F("Done!"));

}


void loop(void) {
  tft.fillScreen(ILI9341_BLACK);
  animation();
  delay(1400);
}



unsigned long introText() {
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(10);
  tft.println("TARS");
  tft.setTextSize(4);
  tft.println("__________");
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_GREEN);

  int w = tft.width();
  int h = tft.height();
  int y;

  for (y=120; y < h;y+=4) tft.drawLine(0, y, w, y+1, ILI9341_RED);
  
  return micros() - start;
}

unsigned long jamsText() {
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(10);
  tft.println("JAMS");
  tft.setTextSize(4);
  tft.println("__________");
  tft.setTextSize(1);
  tft.setTextColor(ILI9341_GREEN);

  int w = tft.width();
  int h = tft.height();
  int y;

  for (y=120; y < h;y+=4) tft.drawLine(0, y, w, y+1, ILI9341_GREEN);
  
  return micros() - start;
}

unsigned long animation() {
  unsigned long start = micros();
  tft.setRotation(1);
  int x,y,z, k, p;
  int w = tft.width();
  int h = tft.height();
  p=0;
  for(z=0; z<12; z+=1) {
    y = random(1, h);
    tft.setTextSize(2);

    k = random(1, 24);
    tft.setCursor(0, p);
    tft.setTextColor(ILI9341_GREEN);
    if (k==1) {
      tft.println("%73d8y12ydc 9h3f...");
    }
    if (k==2) {
      tft.println("kèrourƫ day");
    }
    if (k==3) {
      tft.println("eiƫ =nemihèr if....");
    }
    if (k==4) {
      tft.println("eißłr opare merurƫ");
    }
    if (k==5) {
      tft.println(" ");
    }
    if (k==6) {
      tft.println("Kai de nil saropèrn....");
    }
    if (k==7) {
      tft.println(" ");
    }
    if (k==8) {
      tft.println("Heil shis sdo!");
    }
    if (k==9) {
      tft.println("Vir seim eiß temir");
    }
    if (k==10) {
      tft.println("dous ehiy norvèrn nije");
    }
    if (k==11) {
      tft.println(" ");
    }
    if (k==12) {
      tft.println("Ünus junive eim intz");
    }
    if (k==13) {
      tft.println(" ");
    }
    if (k==14) {
      tft.println("Becsh je nesèr seuhèr");
    }
    if (k==15) {
      tft.println("Gross Perigee...!");
    }
    if (k==16) {
      tft.println("Aber, wie... mir schien..");
    }
    if (k==17) {
      tft.println("Ergebines eine Kroig");
    }
    if (k==18) {
      tft.println("Es war nun Gecht");
    }
    if (k==19) {
      tft.println("deb die Haukeright Ud");
    }
    if (k==20) {
      tft.setTextColor(ILI9341_RED);
      tft.println("I'M GAY!!!!!");
    }
    if (k==21) {
      tft.setTextColor(ILI9341_MAGENTA);
      tft.println("SENPAIS2 DAI SUKI DESU!");
    }
    if (k==22) {
      tft.setTextColor(ILI9341_BLUE);
      tft.println("Nein I'm not GAY! I'm TARS");
    }
    if (k==23) {
      tft.setTextColor(ILI9341_BLUE);
      tft.println("Nein! Nein! Nein!");
    }
    p+=20;
  }
  return micros() - start;
}