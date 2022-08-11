#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class isPrime {
public:
	bool operator()(unsigned int num) {
		for (unsigned int i = 2; i < num; i++) {
			if (num % i == 0)
				return false;
		}
		cout << num << endl;
		return true;
	}
};
int main() {
	unsigned int num;
	cout << "Enter positive integer greater than 1: ";
	cin >> num;
	vector<unsigned int> v(num - 1);
	for (unsigned int i = 0; i < v.size(); i++) {
		v[i] = i + 2;
	}
	//isPrime prime;
	cout << "All prime numbers: " << endl;
	for_each(v.begin(), v.end(), isPrime());
	return 0;
}