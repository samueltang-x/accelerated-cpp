#include "../../ch12-making-class-objects-act-like-values/Str.h"
#include <fstream>
#include <iostream>
#include <string>

using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;

bool  test_Str() {
  Str s1 = "Hello ";
  Str s2 = "world ";
  Str s3 = "!";

  s1 += s2 + s3;
  
  ofstream out("report/test_Str.log");
  out << "output of test_Str():\n" << s1 << endl;
  out.close();

  ifstream in("report/test_Str.log");
  string s;
  getline(in, s);
  getline(in, s);

  return s == "Hello world !";
}
