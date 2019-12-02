#include "gigasecond.h"
gigasecond::ptime gigasecond::advance(ptime time) {
  return time + gigasecond::gigasecond;
}