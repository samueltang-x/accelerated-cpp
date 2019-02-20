#include "6.1.3-finding-urls.h"
#include <algorithm>

using std::find;
using std::find_if;
using std::isalnum;
using std::search;
using std::string;
using std::vector;

bool not_url_char(char c) {
  // characters, in addition to alphanumerics, that can appear in a URL
  static const string url_chars = "~;/?:@=&$-_.+!*'(),";
  return !(isalnum(c) ||
      find(url_chars.begin(), url_chars.end(), c) != url_chars.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
  return find_if(b, e, not_url_char);
}

string::const_iterator url_begin(string::const_iterator b, string::const_iterator e) {
  static const string sep = "://";

  typedef string::const_iterator iter;
  // i marks where the separator was found
  iter i = b;

  while ((i = search(i, e, sep.begin(), sep.end())) != e) {
    // make sure the separator is not at the beginning or end of the line
    if ( i != b || i + sep.size() != e) {
      // beg marks the beginning of the protocol-name
      iter beg = i;
      while (beg != b && isalpha(beg[-1]))
        --beg;

      // is there at least one appropriate character before and after the separator?
      if (beg != i && !not_url_char(i[sep.size()]))
        return beg;
    }
    i += sep.size();
  }
  return e;
}

vector<string> find_urls(const string& s) {
  vector<string> urls;

  typedef string::const_iterator iter;

  iter b = s.begin(), e = s.end();

  while (b != e) {
    // look for one or more letters followed by ://
    b = url_begin(b, e);
    if (b != e) {
      // look for the rest of the URL
      iter end = url_end(b, e);

      urls.push_back(string(b, end));

      b = end;
    }
  }
  return urls;
}

