#include "./read-grammar.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <ctime>

using std::cout;
using std::domain_error;
using std::endl;
using std::ifstream;
using std::logic_error;
using std::ostream_iterator;
using std::rand;
using std::srand;
using std::string;
using std::time;
using std::vector;

bool bracketed(const string& s) {
  return s.size() > 1 && s[0] == '<' && s[s.size() -1] == '>';
}

int nrand(int n) {
  if (n <= 0 || n > RAND_MAX)
    throw domain_error("Argument to nrand is out of range");

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while ( r >= n);

  return r;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& words) {
  if (!bracketed(word)) {
    words.push_back(word);
  } else {
    // locate the rule that corresponds to word
    Grammar::const_iterator it = g.find(word);

    if (it == g.end())
      throw logic_error("rule not found for word: " + word);

    // fetch the set of possible rules
    const Rule_collection& c = it->second;

    // from which we select on at random
    const int rand_num = nrand(c.size());
    const Rule& r = c[rand_num];

    for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
      gen_aux(g, *i, words);
  }
}

vector<string> gen_sentence(const Grammar& g) {
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

int main() {
  srand((unsigned)time(0));

  ifstream grammar_file;
  grammar_file.open("../data/grammar.txt");
  // generate the sentence
  vector<string> sentence = gen_sentence(read_grammar(grammar_file));

  // write the first word, if any
  vector<string>::const_iterator it = sentence.begin();
  if (!sentence.empty()) {
    cout << *it;
    ++it;
  }

  // write the rest of the words, each preceded by a space
  while (it != sentence.end()) {
    cout << " " << *it;
    ++it;
  }

  //copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));

  cout << '.' << endl;
  return 0;
}
