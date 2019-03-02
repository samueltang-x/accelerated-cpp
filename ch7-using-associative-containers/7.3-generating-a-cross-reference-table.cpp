#include "7.3-generating-a-cross-reference-table.h"
#include <algorithm>
#include <istream>
#include <map>

using std::getline;
using std::istream;
using std::map;
using std::string;
using std::vector;

map<string, vector<int> > cross_ref(istream& in,
    vector<string> find_words(const string&)) {
  
  map<string, vector<int> > ret;
  vector<string> words;
  int line_number = 0;
  string line;

  while (getline(in, line)) {
    ++line_number;
    words = find_words(line);

    for (vector<string>::const_iterator it = words.begin();
        it != words.end();
        ++it) {
      ret[*it].push_back(line_number);
    }
  }

  return ret;
}
