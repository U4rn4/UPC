#include "evaluatePrefix.hh"

#include <algorithm>

string evaluatePrefix(BinTree<string> t, int n, bool rev) {
  if (n <= 0)
    return "";
  else if (t.value() == "Concat") {
    if (not rev) {
      string s1, s2;
      s1 = evaluatePrefix(t.left(), n, false);
      s2 = evaluatePrefix(t.right(), n - s1.size(), false);
      return s1 + s2;
    } else {
      string s1, s2;
      s2 = evaluatePrefix(t.right(), n, true);
      s1 = evaluatePrefix(t.left(), n - s2.size(), true);
      return s1 + s2;
    }
  } else if (t.value() == "Reverse") {
    string s1;
    s1 = evaluatePrefix(t.left(), n, not rev);
    reverse(s1.begin(), s1.end());
    return s1;
  } else {
    string s = t.value();
    if (n > s.size())
      return s;
    else if (not rev)
      return s.substr(0, n);
    else {
      return s.substr(s.size()-n, n);
    }
  }
}

string evaluatePrefix(BinTree<string> t, int n) {
  return evaluatePrefix(t,n,false);
}

