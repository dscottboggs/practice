#include "square_root.h"
#include <math.h>

uint16_t
squareRoot(uint16_t x)
{
  return round(exp(log(x) / 2));
}