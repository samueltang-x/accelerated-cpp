#include "Vec.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  Vec<int> vi(2, 3);
  cout << "Vec of int: (using index)";
  for (Vec<int>::size_type i = 0; i != vi.size(); ++i) {
    cout << ' ' << vi[i]; 
  }
  cout << endl;

  Vec<char> vc(2, 'c');
  vc.push_back('b');
  cout << "Vec of char: (using const_iterator)";
  for (Vec<char>::const_iterator i = vc.begin(); i != vc.end(); ++i) {
    cout << ' ' << *i; 
  }
  cout << endl;

  Vec<string> vs;
  vs.push_back("Hello, world.");
  cout << "Vec of string:" << vs[0] << endl;

}
