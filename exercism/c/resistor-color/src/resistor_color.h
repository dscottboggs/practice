#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H
#include <stdint.h>

typedef enum
{
  BLACK,
  BROWN,
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  VIOLET,
  GREY,
  WHITE
} resistor_band_t;

// Return the color for the given value
uint16_t
colorCode(resistor_band_t color);

// Return all colors
resistor_band_t*
colors();

#endif
