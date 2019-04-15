
#include <string>
#include <iostream>
#include <ctype.h>
#include <sstream>

using namespace std;

bool isConsonant(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o'
                    || c == 'u' || c == 'y');
}

string consonatizeHelper(string s, int idx) {

    if (idx == s.length()) return "";
    if (isalpha(s[idx]) && isConsonant(s[idx])) {
        stringstream ss;
        ss << (char)toupper(s[idx]) << consonatizeHelper(s ,idx+1);
        return ss.str();
    }
    return consonatizeHelper(s, idx+1);
}
string consonantize(string s) {
    return consonatizeHelper(s, 0);
}

int main() {
    string tw;
    cout << consonantize("lowercase") << endl;
    cout << consonantize("uppercase")  << endl;
    cout << consonantize("2.718281828459045")  << endl;
    cout << consonantize("'Hi, Mom!'")  << endl;
    cout << consonantize("A") << endl;
    cout << consonantize("+") << endl;
    cout << consonantize("Q") << endl;
    //cout << consonantize("***a khn45363'd*%%'") << endl;
    cout << "Enter a string" << endl;
    getline(cin,tw);
    cout << consonantize(tw)<< endl;
}


