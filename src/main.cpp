#include <Arduino.h>
#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeMonoBold9pt7b.h>

/*#define CS_PIN     15  // CS pin for SPI
#define DC_PIN     D4  // DC pin for SPI
#define RST_PIN    D2  // RST pin for SPI
#define BUSY_PIN   D5  // BUSY pin for SPI

GxEPD2_BW<GxEPD2_290_M06, GxEPD2_290_M06::HEIGHT> display(
    GxEPD2_290_M06(CS_PIN, DC_PIN, RST_PIN, BUSY_PIN)
);
*/
//GxEPD2_BW<GxEPD2_290, GxEPD2_290::HEIGHT> display(GxEPD2_290(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=2*/ 2, /*BUSY=5*/ 5)); // GDEH029A1 128x296, SSD1608 (IL3820)


//GxEPD2_BW<GxEPD2_290,            GxEPD2_290::HEIGHT>        display(GxEPD2_290(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEH029A1 128x296, SSD1608 (IL3820)
//GxEPD2_BW<GxEPD2_290_T5,         GxEPD2_290_T5::HEIGHT>     display(GxEPD2_290_T5(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEW029T5 128x296, UC8151 (IL0373)
//GxEPD2_BW<GxEPD2_290_T5D,        GxEPD2_290_T5D::HEIGHT>    display(GxEPD2_290_T5D(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEW029T5D 128x296, UC8151D
//GxEPD2_BW<GxEPD2_290_I6FD,       GxEPD2_290_I6FD::HEIGHT>   display(GxEPD2_290_I6FD(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEW029I6FD 128x296, UC8151D
//GxEPD2_BW<GxEPD2_290_T94,        GxEPD2_290_T94::HEIGHT>    display(GxEPD2_290_T94(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEM029T94 128x296, SSD1680
//GxEPD2_BW<GxEPD2_290_T94_V2,     GxEPD2_290_T94_V2::HEIGHT> display(GxEPD2_290_T94_V2(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEM029T94 128x296, SSD1680, Waveshare 2.9" V2 variant
//GxEPD2_BW<GxEPD2_290_BS,         GxEPD2_290_BS::HEIGHT>     display(GxEPD2_290_BS(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // DEPG0290BS 128x296, SSD1680
GxEPD2_BW<GxEPD2_290_M06,        GxEPD2_290_M06::HEIGHT>    display(GxEPD2_290_M06(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEW029M06  128x296, UC8151D
//GxEPD2_BW<GxEPD2_290_GDEY029T94, GxEPD2_290_GDEY029T94::HEIGHT> display(GxEPD2_290_GDEY029T94(/*CS=15*/ SS, /*DC=4*/ 4, /*RST=5*/ 5, /*BUSY=16*/ 16)); // GDEY029T94  128x296, SSD1680, (FPC-A005 20.06.15)

void setup() {
    Serial.begin(115200);

    // Initialize display
    display.init();

    // Clear the display
    display.fillScreen(GxEPD_WHITE);
    display.firstPage();

    delay(1000);
}

const char* messages[] = {
    "Hello, world!",
    "Meetings suck!",
    "Nerds Rule!"
};
const int numMessages = sizeof(messages) / sizeof(messages[0]);
int currentMessageIndex = 0;


void loop() {
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
    // Example: Draw text on display using standard font
    display.fillScreen(GxEPD_WHITE); // Clear screen
    display.setTextColor(GxEPD_BLACK);
    display.setTextSize(2); // Set text size
    display.setCursor(10, 50); // Set text position
    display.println(messages[currentMessageIndex]);
    display.nextPage(); // Update display

currentMessageIndex = (currentMessageIndex + 1) % numMessages;

    delay(50000); // Wait for 5 seconds
}