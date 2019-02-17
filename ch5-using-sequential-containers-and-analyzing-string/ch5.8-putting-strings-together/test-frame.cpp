#include "frame.h"
#include <iostream>
#include <istream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

int main() {
  vector<string> v, p;
  cout << "Please enter the sentance to frame: " << endl;

  string x;
  while (getline(cin, x))
    v.push_back(x);

  p = frame(v);

  cout << endl << "framed character picture:" << endl;
  for (vector<string>::size_type i = 0; i != p.size(); ++i)
    cout << p[i] << endl;
  return 0;
}
