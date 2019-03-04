#include <fstream>
#include <string>
#include <vector>

class Student_info {
  public:
    Student_info();
    Student_info(std::ifstream&);

    std::string name() const { return n; }
    double grade() const;
    bool valid() const { return !homework.empty(); }

    std::ifstream& read(std::ifstream&);

  private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
