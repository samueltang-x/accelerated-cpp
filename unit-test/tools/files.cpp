#include "files.h"

#include <iostream>
#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::string;

bool areSameContentFiles(string file1, string file2) {
  ifstream f1(file1);
  ifstream f2(file2);

  if (!f1) {
    cerr << "file '" << file1 << "' doesn't exist." << endl;
    return false;
  }
  if (!f2) {
    cerr << "file '" << file2 << "' doesn't exist." << endl;
    return false;
  }

  string line_f1, line_f2;
  int index_f1 = 0, index_f2 = 0;

  while(getline(f1, line_f1)) {
    ++index_f1;

    if (!getline(f2, line_f2)) {
      return false;
    }

    ++index_f2;
    if (line_f1 != line_f2) {
      return false;
    }
  }

  if (getline(f2, line_f2)) {
    ++index_f2;
    return false;
  }

  return true;
}
