#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

#define ROW 1
#define COLUMN 1
#define FONT SystemFont5x7
#define FONT1 Arial_Black_16

#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1

# include  <LogoElektro.h>
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
DMD led_module(ROW, COLUMN);
void scan_module()
{
  led_module.scanDisplayBySPI();
}
void setup() {
  Serial.begin(9600);
  Timer1.initialize(2000);
  Timer1.attachInterrupt(scan_module);
  led_module.clearScreen( true );

}

void loop() {

  led_module.clearScreen( true );
//   led_module.drawBox(  0,  0, (32*DISPLAYS_ACROSS)-1, (16*DISPLAYS_DOWN)-1, GRAPHICS_NORMAL );
  led_module.selectFont(FONT);
  led_module.drawString(  0, 0, "Domar", 5, GRAPHICS_NORMAL );
  led_module.drawString( 7, 9, "Cafe", 5, GRAPHICS_NORMAL );
  delay(5000);
  led_module.clearScreen( true );
  led_module.drawString(  0, 0, "Hot       ", 5, GRAPHICS_NORMAL );
  led_module.drawString(  0, 8, "Drinks", 5, GRAPHICS_NORMAL );
  delay(2000);
  led_module.clearScreen( true );
  led_module.drawString(  0, 0, "Cold     ", 5, GRAPHICS_NORMAL );
  led_module.drawString(  0, 8, "Drinks", 5, GRAPHICS_NORMAL );
  delay(2000);
  led_module.clearScreen( true );
  led_module.drawString(  0, 0, "Momo&", 5, GRAPHICS_NORMAL );
  led_module.drawString(  0, 8, "Momos   ", 5, GRAPHICS_NORMAL );
  delay(2000);

  led_module.clearScreen( true );
//  led_module.selectFont(FONT1);
//  led_module.clearScreen( true );
//  led_module.drawMarquee("Tea,Coffee,Bakery Item & many more ...", 50, (32 * ROW), 0);
//  long start = millis();
//  long timming = start;
//  boolean flag = false;
//  while (!flag)
//  {
//    if ((timming + 20) < millis())
//    {
//      flag = led_module.stepMarquee(-1, 0);
//      timming = millis();
//    }
//  }

}
