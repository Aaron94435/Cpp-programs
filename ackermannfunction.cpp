#include <iostream>
using namespace std;
int ackermannFunc(int m, int n);
int c = 0;
int main() {
	int m, n;
	cout << "Enter m value: ";
	cin >> m;
	cout << "Enter n value: ";
	cin >> n;
	cout << "ackermann value: " << ackermannFunc(m, n) << endl;
	cout << "Recursion count: " << c << endl;
	return 0;
}
int ackermannFunc(int m, int n) {
	c++;
	if (m == 0) {
		return n + 1;
	}
	else if (n == 0) {
		
		return ackermannFunc(m - 1, 1);
	}
	
	return ackermannFunc(m - 1, ackermannFunc(m, n - 1));
}