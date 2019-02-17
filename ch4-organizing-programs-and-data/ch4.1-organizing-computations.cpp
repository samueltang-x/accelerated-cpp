#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;
using std::vector;
using std::sort;
using std::domain_error;

// compute the median of a vector<double>
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();

  if (size == 0)
    throw domain_error("median of an empty vector");

  sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid - 1]) / 2 : vec[mid];
}

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
double grade(double midterm, double final, vector<double>& hw) {
  if (hw.size() == 0)
    throw domain_error("Student has done no homework");

  return grade(midterm, final, median(hw));
}

int main() {
  // ask for and read the student's name
  cout << "Please enter your name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for and read the homework grades
  cout << "Enter all your homework grades, "
    "followed by end-of-file: ";

  // a variable into which to read
  double x;
  vector<double> homework;

  // invariant:
  // we have read count grades so far, and
  // sum is the sum of the first count grades
  while (cin >> x) {
    homework.push_back(x);
  }


  // write the result
  streamsize prec = cout.precision();
  cout << "Your final grade is: " << setprecision(3)
    << grade(midterm, final, homework)
    << setprecision(prec) << endl;

  return 0;
}
