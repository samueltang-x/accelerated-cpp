#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your name: ";

  std::string name;
  std::cin >> name;

  using std::cout;
  using std::cin;
  using std::endl;
  using std::string;
  
  // the number of blanks surrounding the greeting
  const int pad = 1;

  // total number of rows to write
  const int rows = pad * 2 + 3;

  // separate the output from the input
  cout << endl;

  const string greeting = "Hello, " + name + "!";

  // total number of columns to write
  const string::size_type cols = greeting.size() + pad * 2 + 2;

  for (int r = 0; r != rows; ++r) {
    string::size_type c = 0;

    while (c != cols) {
      if (r == pad + 1 && c == pad + 1) {
        // write the greeting and adjust the columns
        cout << greeting;
        c += greeting.size();
      } // end of writting greeting
      else {
        if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
          cout << "*";  // write a asterisk
        else
          cout << " ";  // write a space

        ++c;
      }
    } // end of while loop

    cout << endl; // write new line and end current row
  } // end of for loop

  return 0;
}
