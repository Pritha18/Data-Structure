
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 5;

	// declaring an array
	int pritha[n] = { 7, 3, 12, 9, 6};


	// ascending
	for (int i = 0; i < n; ++i) {
		int minValue = INT_MAX;
		int minIndex;

		for (int j = i; j < n; ++j) {
			if (pritha[j] < minValue) {
				minValue = pritha[j];
				minIndex = j;
			}
		}

		int temp = pritha[i];
		pritha[i] = minValue;
		pritha[minIndex] = temp;
	}

	// display the sorted array
	cout << "Ascending order" << endl;
	for (int i = 0; i < n; ++i) {
		cout << pritha[i] << " ";
	}
	cout << endl << endl;

	// decending
	for (int i = 0; i < n; ++i) {
		int maxValue = INT_MIN;
		int maxIndex;

		for (int j = i; j < n; ++j) {
			if (pritha[j] > maxValue) {
				maxValue = pritha[j];
				maxIndex = j;
			}
		}

		int temp = pritha[i];
		pritha[i] = maxValue;
		pritha[maxIndex] = temp;
	}

	// display the sorted array
	cout << "Decending order" << endl;
	for (int i = 0; i < n; ++i) {
		cout << pritha[i] << " ";
	}
	cout << endl;

	return 0;
}