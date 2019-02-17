#include "split.h"
#include <cctype>

using std::isspace;
using std::string;
using std::vector;

vector<string> split(const string& s) {
  vector<string> words;

  typedef string::size_type string_size;
  string_size i = 0;

  // invariant: we have processed charachters [original value of i, i)
  while (i != s.size()) {
    while (i != s.size() && isspace(s[i]))
      ++i;

    string_size j = i;
    while (j != s.size() && !isspace(s[j]))
      ++j;

    if (i != j) {
      words.push_back(s.substr(i, j - i));
      i = j;
    }
  
  }
  return words;
}

