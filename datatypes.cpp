#include <string>
#include <iostream>
#include <sstream>
using namespace std;
template <class T>
T absolutevalue(T num) {
	return num < 0 ? -1 * num : num;
}
int main() {
	string s;
	while (true) {
		short a;
		cout << "Enter a short or just enter to move to next data type:";
		getline(cin, s);
		if (s == "")
			break;
		//cin.ignore(1, '\n');
		a = static_cast<short>(stoi(s));
		cout << "The absolute value of " << a << " is: " << absolutevalue(a) << endl;
	}
	cout << endl << endl;
	while (true) {
		int a;
		cout << "Enter an int or just enter to move to next data type:";
		getline(cin, s);
		if (s == "")
			break;
		//cin.ignore(1, '\n');
		a = stoi(s);
		cout << "The absolute value of " << a << " is: " << absolutevalue(a) << endl;
	}
	cout << endl << endl;
	while (true) {
		double a;
		cout << "Enter a double or just enter to move to next data type:";
		getline(cin, s);
		if (s == "")
			break;
		//cin.ignore(1, '\n');
		a = stod(s);
		cout << "The absolute value of " << a << " is: " << absolutevalue(a) << endl;
	}
	cout << endl << endl;
	while (true) {
		float a;
		cout << "Enter a float or just enter to move to next data type:";
		getline(cin, s);
		if (s == "")
			break;
		//cin.ignore(1, '\n');
		a = stof(s);
		cout << "The absolute value of " << a << " is: " << absolutevalue(a) << endl;
	}
	cout << endl << endl;
	while (true) {
		long a;
		cout << "Enter a long or just enter to move to next data type:";
		getline(cin, s);
		if (s == "")
			break;
		//cin.ignore(1, '\n');
		a = stol(s);
		cout << "The absolute value of " << a << " is: " << absolutevalue(a) << endl;
	}
	cout << endl << endl;
	return 0;
}