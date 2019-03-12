#ifndef GUARD_Str_h
#define GUARD_Str_h

#include "../ch11-defining-abstract-data-types/Vec.h"

class Str {
  friend std::istream& operator>>(std::istream, Str&);

  public:
    typedef Vec<char>::size_type size_type;

    //default constructor; crate an empty Str
    Str() {}

    // create a Str containing n copies of c
    Str(size_type n, char c): data(n, c) {}

    // create a Str from a null-terminated array of char
    Str(const char* cp) {
      std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }

    // create s Str from the range denoted by iterators b and e
    template <class In> Str(In b, In e) {
      std::copy(b, e, std::back_inserter(data));
    }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    size_type size() const { return data.size(); }

    Str& operator+=(const Str& s) {
      std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
      return *this;
    }

  private:
    Vec<char> data;
};

std::ostream& operator<<(std::ostream& os, const Str& s) {
  for (Str::size_type i = 0; i != s.size(); ++i)
    os << s[i];
  return os;
}

std::istream& operator>>(std::istream& is, Str& s) {
  s.data.clear();

  char c;
  while (is.get(c) && isspace(c))
    ;

  if (is) {
    do s.data.push_back(c);
    while (is.get(c) && !isspace(c));

    if(is) {
      is.unget();
    }
  }

  return is;
}

Str& operator+(const Str& s1, const Str& s2) {
  Str t = s1;
  t += s2;
  return t;
}

#endif
