#include <iostream>
int* ArrayExpander(int arr[], int size);
int main() {
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int* newarr = ArrayExpander(array, 10);
	for (int i = 0; i < 20; i++) {
		std::cout << newarr[i] << std::endl;
	}
}
int* ArrayExpander(int arr[], int size) {
	int* newArr = new int[size * 2];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	for (int i = size; i < (size * 2); i++) {
		newArr[i] = 0;
	}
	return newArr;
}