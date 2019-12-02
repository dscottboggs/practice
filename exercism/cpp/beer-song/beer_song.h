#ifndef BEER_H
#define BEER_H
#include <sstream>
#define EXERCISM_RUN_ALL_TESTS
namespace beer {
std::string verse(int verseNumber) {
  switch (verseNumber) {
  case 2:
    return std::string{
        "2 bottles of beer on the wall, 2 bottles of beer.\n"
        "Take one down and pass it around, 1 bottle of beer on the wall.\n"};
  case 1:
    return std::string{"1 bottle of beer on the wall, 1 bottle of beer.\n"
                       "Take it down and pass it around, no more bottles of "
                       "beer on the wall.\n"};
  case 0:
    return "No more bottles of beer on the wall, no more bottles of beer.\n"
           "Go to the store and buy some more, 99 bottles of beer on the "
           "wall.\n";
  default:
    std::ostringstream out;
    out << verseNumber << " bottles of beer on the wall, " << verseNumber
        << " bottles of beer.\n"
           "Take one down and pass it around, "
        << verseNumber - 1 << " bottles of beer on the wall.\n";
    return out.str();
  }
}
std::string sing(int first, int last = 0) {
  if (first == last)
    return verse(first);
  return verse(first) + '\n' + sing(first - 1, last);
}
} // namespace beer
#endif // BEER_H