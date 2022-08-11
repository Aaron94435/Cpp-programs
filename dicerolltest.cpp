#include <iostream>
#include <random>
#include <regex>
#include <string>
using namespace std;
int* getInput(const string& str);
int main() {
	random_device r;
	string s;
	regex p ("![0-9]+d[0-9]+");
	cout << "Enter your dice roll. Must be in the format int d int: ";
	getline(cin, s);
	if (regex_match(s, p)) {
		int* nums = getInput(s);
		int times = nums[0];
		int sides = nums[1];
		uniform_int_distribution<int> dist(1, sides);
		int* generated = new int[times];
		cout << "[";
		for (int i = 0; i < times - 1; i++) {
			generated[i] = dist(r);
			cout << generated[i] << ", ";
		}
		generated[times - 1] = dist(r);
		cout << generated[times - 1] << "]" << endl;
	}
	else
		cout << "It does not work!" << endl;

	return 0;
}
int* getInput(const string& str) {
	int* arr = new int[2];
	size_t pos = str.find("d");
	arr[0] = stoi(str.substr(1, pos));
	arr[1] = stoi(str.substr(pos + 1));
	return arr;
}