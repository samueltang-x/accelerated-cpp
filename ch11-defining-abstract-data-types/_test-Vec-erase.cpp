#include "Vec.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  char c = 'c';
  Vec<char> vc(1, c);
  vc.push_back('d');

  vc.erase(vc.begin());

  for (Vec<char>::const_iterator i = vc.begin(); i != vc.end(); ++i)
    cout << *i << endl;
  return 0;
}
