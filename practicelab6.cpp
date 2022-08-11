#include <iostream>
#include <string>
using namespace std;
void dispReverse(const string& s);
void recReverse(const string& s, int length);
int main() {
	string s;
	cout << "Enter a string: ";
	getline(cin, s);
	dispReverse(s);
	return 0;
}
void dispReverse(const string& s) {
	int length = s.length();
	recReverse(s, length);
}
void recReverse(const string& s, int length) {
	if (length != 0) {
		cout << s[length - 1];
		recReverse(s, --length);
	}
}