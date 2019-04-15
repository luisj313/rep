
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string aSequence(int);
string bSequence(int);

string complement(string s, int i) {
  if (i == s.length())
    return "";
  stringstream ss;
  if (s[i] == 'A')
    ss << 'B' << complement(s, i + 1);
  else if (s[i] == 'B')
    ss << 'A' << complement(s, i + 1);
  return ss.str();
}

void error(string s) { cout << "error: " << s << endl; }

string aSequence(int n) {
  if (n == 0)
    return "A";
  stringstream ss;
  string asdf = aSequence(n - 1);
  ss << asdf << complement(asdf, 0);
  return ss.str();
}

string bSequence(int n) {
  if (n == 0)
    return "B";
  stringstream ss;
  string asdf = bSequence(n - 1);
  ss << asdf << complement(asdf, 0);
  return ss.str();
}

int main() {
   if(true) {
    int i = 0;
    cout << "enter length of sequence: ";
    cin >> i;
    cout << endl << aSequence(i) << endl << bSequence(i) << endl;
  }
}

