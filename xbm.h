// Images can be converted to XBM format by using the online converter here:
// https://www.online-utility.org/image/convert/to/XBM

// The output must be pasted in a header file, renamed and adjusted to appear
// as as a const unsigned char array in PROGMEM (FLASH program memory).

// The xbm format adds padding to pixel rows so they are a whole number of bytes
// In this example 50 pixel width means 56 bits = 7 bytes
// the 50 height then means array uses 50 x 7 = 350 bytes of FLASH
// The library ignores the padding bits when drawing the image on the display.

// Example of the correct format is shown below

#include <pgmspace.h>  // PROGMEM support header

// Espressif logo 50 x 50 pixel array in XBM format
#define logoWidth  50  // logo width
#define logoHeight 50  // logo height

// Image is stored in this array
PROGMEM const unsigned char logo[] = {
  0xFF, 0xFF, 0x0F, 0xD0, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0x01, 0x00, 0xFE, 
  0xFF, 0x03, 0xFF, 0x3F, 0x00, 0x00, 0xF0, 0xFF, 0x03, 0xFF, 0x1F, 0x00, 
  0x00, 0xE0, 0xFF, 0x03, 0xFF, 0x07, 0x00, 0x00, 0x80, 0xFF, 0x03, 0xFF, 
  0x03, 0x00, 0x00, 0x00, 0xFF, 0x03, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFC, 
  0x03, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x03, 0x3F, 0x00, 0x00, 0x00, 
  0x00, 0xF0, 0x03, 0x3F, 0x00, 0x80, 0x03, 0x00, 0xF0, 0x03, 0x1F, 0x00, 
  0x80, 0x73, 0x00, 0xC0, 0x03, 0x0F, 0x00, 0x80, 0x73, 0x00, 0xC0, 0x03, 
  0x0F, 0x00, 0x9E, 0x71, 0x00, 0x80, 0x03, 0x07, 0x00, 0xFF, 0x33, 0x00, 
  0x80, 0x03, 0x07, 0x00, 0xFF, 0x3F, 0x00, 0x00, 0x03, 0x03, 0x00, 0xF8, 
  0xFF, 0x00, 0x00, 0x03, 0x03, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0x02, 0x03, 
  0x00, 0xF0, 0xF9, 0x03, 0x00, 0x02, 0x01, 0x00, 0xF8, 0xE0, 0x07, 0x00, 
  0x02, 0x01, 0x00, 0xF8, 0xC0, 0x07, 0x00, 0x02, 0x00, 0x00, 0xF8, 0xC0, 
  0x0F, 0x00, 0x00, 0x01, 0x00, 0x7C, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 
  0xFC, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0xFC, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x3E, 0xFF, 0x01, 
  0x00, 0x00, 0x00, 0x00, 0x3E, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3E, 
  0xF0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xE0, 0x07, 0x00, 0x00, 0x00, 
  0xA0, 0x1F, 0xC0, 0x07, 0x00, 0x00, 0x01, 0xE0, 0x1F, 0xE0, 0x07, 0x00, 
  0x02, 0x01, 0xF0, 0xFF, 0xF0, 0x07, 0x00, 0x02, 0x01, 0xC0, 0xFF, 0xFF, 
  0x03, 0x00, 0x02, 0x03, 0x00, 0xFC, 0xFF, 0x03, 0x00, 0x03, 0x03, 0x00, 
  0xEE, 0xFF, 0x01, 0x00, 0x03, 0x03, 0x00, 0xCE, 0x7D, 0x00, 0x00, 0x03, 
  0x07, 0x00, 0xCE, 0x01, 0x00, 0x80, 0x03, 0x0F, 0x00, 0xCF, 0x00, 0x00, 
  0x80, 0x03, 0x0F, 0x00, 0xE4, 0x00, 0x00, 0xC0, 0x03, 0x1F, 0x00, 0xC0, 
  0x00, 0x00, 0xC0, 0x03, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x3F, 
  0x00, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xF8, 
  0x03, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x03, 0xFF, 0x01, 0x00, 0x00, 
  0x00, 0xFE, 0x03, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xFF, 0x03, 0xFF, 0x0F, 
  0x00, 0x00, 0xC0, 0xFF, 0x03, 0xFF, 0x3F, 0x00, 0x00, 0xF0, 0xFF, 0x03, 
  0xFF, 0xFF, 0x01, 0x00, 0xFE, 0xFF, 0x03, 0xFF, 0xFF, 0x07, 0xC0, 0xFF, 
  0xFF, 0x03, };
