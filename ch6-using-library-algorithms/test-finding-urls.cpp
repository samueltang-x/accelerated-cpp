#include "6.1.3-finding-urls.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string s;

  cout << "Enter the context from which to find URLs:" << endl;
  getline(cin, s);
  vector<string> urls = find_urls(s);

  cout << endl << "URLs found:" << endl;
  for (vector<string>::size_type i = 0; i != urls.size(); ++i) {
    cout << urls[i] << endl;
  }

  return 0;
}
