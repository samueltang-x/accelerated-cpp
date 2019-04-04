#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <string>
#include <vector>


class Core {
  public:
    Core(): midterm(0), final(0) {}
    Core(std::istream& is) { read(is); }
    virtual ~Core() {}

    std::string name() const;

    virtual std::istream& read(std::istream&);
    virtual double grade() const;

  protected:
    std::istream& read_common(std::istream&);

    double midterm, final;
    std::vector<double> homework;

  private:
    std::string n;
};

bool compare(const Core&, const Core&);
bool compare_grade(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

#endif
