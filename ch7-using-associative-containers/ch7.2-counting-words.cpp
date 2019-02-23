#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;;
using std::map;
using std::string;

int main() {
  map<string, int> counters;
  string s;

  while (cin >> s)
    ++counters[s];

  for (map<string, int>::iterator it = counters.begin();
      it != counters.end();
      ++it) {
    cout << it->first << ": " << it->second << endl; 
  }
  return 0;
}
