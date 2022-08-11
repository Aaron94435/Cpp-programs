#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	stack<char> cstack;
	string s;
	int left = 0, right = 0;
	cout << "Enter a string: ";
	getline(cin, s);
	auto it = s.begin();
	while (it != s.end()) {
		cstack.push(*it);
		it++;
	}
	while (!cstack.empty()) {
		char c = cstack.top();
		if (c == '{' || c == '[' || c == '(') {
			left++;
		}
		else if (c == ')' || c == ']' || c == '}') {
			right++;
		}
		cstack.pop();
	}
	if (left == 0 && right == 0) {
		cout << "This string has no parenthesis!" << endl;
	}	
	else if (left == right) {
		cout << "This string has balanced parenthesis!" << endl;
	}
	else {
		cout << "This string does not have balanced parenthesis!" << endl;
	}
	return 0;
}