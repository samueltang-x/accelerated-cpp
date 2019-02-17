#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;
using std::vector;
using std::sort;

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

  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  if (size == 0) {
    cout << endl << "You must enter your grades. "
      "Please try again." << endl;

    return 1;
  }

  sort(homework.begin(), homework.end());

  vec_sz mid = size / 2;
  double median = size % 2 == 0 ? (homework[mid - 1] + homework[mid]) / 2 : homework[mid];

  // write the result
  streamsize prec = cout.precision();
  cout << "Your final grade is: " << setprecision(3)
    << 0.2 * midterm + 0.4 * final + 0.4 * median
    << setprecision(prec) << endl;

  return 0;
}
