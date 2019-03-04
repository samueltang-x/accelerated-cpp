#include "grade.h"

using std::ifstream;
using std::string;
using std::vector;

// read homework grades from input stream(standard input stream or file, etc.)
template<class Is>
Is& read_hw(Is& in, vector<double>& hw) {
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

Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(ifstream& is) { read(is); }

bool compare(const Student_info& x, const Student_info& y) {
  return x.name() < y.name();
}

ifstream& Student_info::read(ifstream& in) {
  in >> n >> midterm >> final;
  read_hw(in, homework);
  return in;
}

double Student_info::grade() const {
  return ::grade(midterm, final, homework);
}
