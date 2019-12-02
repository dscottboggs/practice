#include "resistor_color.h"

uint16_t
colorCode(resistor_band_t color)
{
  return color;
}

static resistor_band_t all_colors[10] = { 0 };

resistor_band_t*
colors()
{
  if (all_colors[9] != 0)
    return all_colors;
  for (int i = 0; i < 10; i++)
    all_colors[i] = i;
  return all_colors;
}
