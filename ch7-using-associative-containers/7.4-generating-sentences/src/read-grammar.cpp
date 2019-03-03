#include "../../../ch6-using-library-algorithms/6.1.1-another-way-to-split.h"
#include "read-grammar.h"
#include "iostream"
#include "string"

using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::string;
using std::vector;

Grammar read_grammar(ifstream& in) {
  Grammar ret;
  string line;

  while (getline(in, line)) {
    // split the input into words
    vector<string> entry = split(line);

    if (!entry.empty()) {
      // use the category to store the associated rule
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
  } 

  return ret;
}
