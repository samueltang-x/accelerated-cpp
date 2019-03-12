#include "../ch6-using-library-algorithms/6.1.1-another-way-to-split.h"
#include "../ch9-defining-new-types/9.3-protection/Student_info.h"
#include "test-Vec.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cerr;
using std::domain_error;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::ios_base;
using std::max;
using std::ofstream;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

static string REPORT_FILE = "../report/test-Vec.log";

int test_vec_int() {
  ofstream out(REPORT_FILE.c_str());

  Vec<int> vi(3, 5);
  out << "Vec of int, Vec(size_type, const T&), index:" << endl << ' ';
  for (Vec<int>::size_type i = 0; i != vi.size(); ++i)
    out << ' ' << vi[i];
  out << endl;
  out << "--- End ---" << endl << endl;

  return 0;
}

int test_vec_char() {
  ofstream out(REPORT_FILE.c_str(), ios_base::app);

  Vec<char> vc;
  string hello("Hello, world!");
  for (string::const_iterator i = hello.begin(); i != hello.end(); ++i)
    vc.push_back(*i);

  out << "Vec of char, Vec.push_back, const_iterator:" << endl << "  ";
  for (Vec<char>::const_iterator iv = vc.begin(); iv != vc.end(); ++iv)
    out << *iv;
  out << endl;
  out << "--- End ---" << endl << endl;

  return 0;
}

int test_vec_students() {
  Vec<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  ifstream inFile("data/students-data.txt");
  if (!inFile) {
    cerr << "Failed to open input file: data/students-data.txt" << endl;
    return 1;
  }

  while (record.read(inFile)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  ofstream out(REPORT_FILE.c_str(), ios_base::app);

  out << "Vec of Student_info, Vec.push_back, size_type:" << endl;
  out << "  final grados of students:" << endl;

  for (Vec<Student_info>::size_type i = 0; i != students.size(); ++i) {
    out << "    " << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');

    try {
      double final_grade = students[i].grade();
      streamsize prec = out.precision();
      out << setprecision(3) << final_grade
        << setprecision(prec) << endl;
    } catch (domain_error e) {
      out << e.what() << endl;
    }
  }
  out << "--- End ---" << endl << endl;;
  return 0;
}

string test_vec_clear_erase() {
  string s = "failed";
  Vec<string> vs(1, s);
  vs.clear();
  vs.push_back("It");
  vs.push_back("not");
  vs.push_back("succeed");
  vs.push_back(".");
  
  Vec<string>::iterator it = vs.begin();
  while (it != vs.end()) {
    if (*it == "not")
      it = vs.erase(it);
    else
      ++it;
  }

  string ret = "";
  for (Vec<string>::const_iterator i = vs.begin(); i != vs.end(); ++i)
    ret = ret + ' ' + *i;

  return ret;
}
