#include "concat-strings.h"
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

  vector<string> vp = vcat(v, p);
  cout << endl << "vcat pictures:" << endl;
  for (vector<string>::size_type i = 0; i != vp.size(); ++i)
    cout << vp[i] << endl;

  vector<string> hp = hcat(v, p);
  cout << endl << "hcat pictures:" << endl;
  for (vector<string>::size_type i = 0; i != hp.size(); ++i)
    cout << hp[i] << endl;

  return 0;
}
