#include <map>
#include <string>

namespace word_count {
const auto
words(const std::string& text)
{
  std::map<std::string, int> wc;
  size_t start = 0;
  size_t end = 0;
  while ((end = text.substr(start, text.size() - 1).find_first_of(", \n:")) !=
         std::string::npos) {
    const std::string word(text.substr(start, end));
    wc[word]++;
    start = end;
  }
  return wc;
}
}
