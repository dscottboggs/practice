#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H
#include <iostream>
#include <map>
#include <string>
namespace nucleotide_count {
class counter
{
private:
  std::map<char, int> data;

  constexpr char index_validated(const char c) const
  {
    switch (c) {
      case 'A':
      case 'C':
      case 'G':
      case 'T':
        return c;
      default:
        throw std::invalid_argument("received invalid nucleotide");
    }
  }

public:
  counter(const std::string& text)
    : data({ { 'A', 0 }, { 'C', 0 }, { 'G', 0 }, { 'T', 0 } })
  {
    for (char c : text)
      data[index_validated(c)] += 1;
  }

  const std::map<char, int>& nucleotide_counts() const { return data; }

  int count(const char n) const { return data.at(index_validated(n)); }
};
}

#endif // NUCLEOTIDE_COUNT_H
