#include <Arduino.h>
#include <Adafruit_GFX.h>           // Core library for graphics (GFX)  & text 
#include <PL_smallEPD.h>            // Generic library for UC8156-based EPDs from Plastic Logic
#include "PL_smallLegio.h"          // Display-specific library for 4pigment media (Legio, 6colors)


#include "a_PL_148x70pxl_display.h"            // Imported image (as bytestream) from PL Image Inverter tool 
#include "VerticalGreyScale.h"            // Imported image (as bytestream) from PL Image Inverter tool 
#include "Test2.h"            // Imported image (as bytestream) from PL Image Inverter tool 

#define EPD_RST     12
#define EPD_BUSY    9
#define EPD_CS      5
    

 
 
PL_smallEPD epd(EPD_CS, EPD_RST, EPD_BUSY);     // Declare 4pigment based EPD instance with 6 colors
//PL_smallLegio epd(EPD_CS, EPD_RST, EPD_BUSY);   
  

void setup() {  

    SPI.begin();                    // SPI initialisation, UC8156 supp. max 10Mhz (writing) & 
    SPI.beginTransaction(SPISettings(6000000, MSBFIRST, SPI_MODE0));      // 6.6Mhz (reading)


    epd.begin(EPD_BLACK);           // EPD initialisation & ClearScreen
    epd.showImage(VerticalGreyScale);     // Load image byte stream and trigger an update 
    delay(2000);
    epd.begin(EPD_BLACK);           // EPD initialisation & ClearScreen
    epd.showImage(a_PL_148x70pxl_display);     // Load image byte stream and trigger an update    
 //   epd.begin(EPD_WHITE);      
}

void loop() {      
//      epd.begin(EPD_BLACK);           // EPD initialisation & ClearScreen
   //  epd.showImage(tricolor_red, EPD_UPD_4GL_FULL, COLORTYPE_RED);     // Load image byte stream and trigger an update
//    delay(5000);
 //epd.showImage(inch_Lectum_from_DMA_change);     // Load image byte stream and trigger an update

/*    epd.showImage(Test1);     // Load image byte stream and trigger an update
     delay(5000);
     epd.clearScreen(EPD_BLACK);     // ClearScreen
     epd.showImage(Test2);     // Load image byte stream and trigger an update   
     delay(5000);
     epd.clearScreen(EPD_BLACK);     // ClearScreen
*/
 
}
