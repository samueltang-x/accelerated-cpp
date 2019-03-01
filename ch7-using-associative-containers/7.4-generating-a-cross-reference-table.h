#ifndef GUARD_7_4_generating_a_cross_reference_table_h
#define GUARD_7_4_generating_a_cross_reference_table_h

#include "../ch6-using-library-algorithms/6.1.1-another-way-to-split.h"
#include <istream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::vector<int> > cross_ref(std::istream&,
    std::vector<std::string> find_words(const std::string&) = split);

#endif
