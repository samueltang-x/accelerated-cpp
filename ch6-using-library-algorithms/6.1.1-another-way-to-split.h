#ifndef GUARD_6_1_1_split_h
#define GUARD_6_1_1_split_h

#include <string>
#include <vector>

// wrap the library function isspace() to use its char version
bool space(char);

// wrap the library function isspace() to use its char version
bool not_space(char);

std::vector<std::string> split(const std::string&);

#endif
