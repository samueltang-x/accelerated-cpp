#include "../tools/files.h"
#include "test-tool-files.h"

using std::string;

bool test_areSameContentFiles() {
  string expected("expect/test-areSameContentFiles.txt");
  string report1("data/test-areSameContentFiles-1.txt");

  return areSameContentFiles(expected, report1);
} 

bool test_areSameContentFiles_diff() {
  string expected("expect/test-areSameContentFiles.txt");
  string report2("data/test-areSameContentFiles-2.txt");

  return areSameContentFiles(expected, report2);
} 
