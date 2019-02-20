#include "read.h"

using std::istream;
using std::vector;

istream& read(istream& in; Student_info s) {
  // read and store the student's name and midterm and final exam grades
  in >> s.name >> s.midterm >> s.final;

  read_hw(in, s.homework); // read and store all the student's homework grades

  return in;
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    hw.clear(); // get rid of previous contents

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }

  return in;
}
