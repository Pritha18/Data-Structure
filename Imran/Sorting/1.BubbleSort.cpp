
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 5;

	// declaring an array
	int pritha[n] = { 7, 3, 12, 9, 6};

	// sort the array using bubble sort

	// i < n, indicates 0 to n-1
	// i < n - 1, indicates to n - 2
	// ascending
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (pritha[j] > pritha[j + 1]) {
				int temp = pritha[j];
				pritha[j] = pritha[j + 1];
				pritha[j + 1] = temp;
			}

			// local temp don't exist here
			// cout << temp << endl; // it will show error
		}
	}

	// display the sorted array
	cout << "Ascending order" << endl;
	for (int i = 0; i < n; ++i) {
		cout << pritha[i] << " ";
	}
	cout << endl << endl;

	// decending
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			if (pritha[j] < pritha[j + 1]) {
				int temp = pritha[j];
				pritha[j] = pritha[j + 1];
				pritha[j + 1] = temp;
			}
		}
	}

	// display the sorted array
	cout << "Decending order" << endl;
	for (int i = 0; i < n; ++i) {
		cout << pritha[i] << " ";
	}
	cout << endl;

	return 0;
}