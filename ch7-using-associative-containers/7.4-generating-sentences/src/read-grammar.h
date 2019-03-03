#ifndef GUARD_read_grammar_h
#define GUARD_read_grammar_h

#include <fstream>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::ifstream&);

#endif
