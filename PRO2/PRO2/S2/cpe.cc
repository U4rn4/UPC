#include <iostream>
using namespace std;

int avalu () {
    char c,g;
    cin >> c;
    if (c=='(') {
        int a = avalu();
        cin >> c;
        int b = avalu();
        cin >> g;
        if (c == '+') return a+b;
        else if (c == '-') return a-b;
        else if (c == '*') return a*b;
    } else if (c!=')') return c-'0';
}

int main () {
	cout << avalu() << endl;
}