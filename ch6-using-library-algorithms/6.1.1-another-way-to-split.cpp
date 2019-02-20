#include "6.1.1-another-way-to-split.h"
#include <algorithm>
#include <cctype>

using std::find_if;
using std::isspace;
using std::string;
using std::vector;

// wrap the library function isspace() to use its char version
bool space(char c) {
  return isspace(c);
}

// wrap the library function isspace() to use its char version
bool not_space(char c) {
  return !isspace(c);
}

vector<string> split(const string& s) {
  vector<string> ret;

  typedef string::const_iterator iter;

  iter b = s.begin();
  while (b != s.end()) {
    // ignore leading blanks
    b = find_if(b, s.end(), not_space);

    iter e = find_if(b, s.end(), space);
    
    if (b != s.end())
      ret.push_back(string(b, e));

    b = e;
  }

  return ret;
}

