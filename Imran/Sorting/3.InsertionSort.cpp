
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 5;

	// declaring an array
	int pritha[n] = { 7, 3, 12, 9, 6};


	// ascending
	for (int i = 1; i < n; ++i) {
		int holePosition = i;
		int holePositionValue = pritha[i];

		for (int j = i - 1; j >= 0 && pritha[j] > holePositionValue; --j) {
			pritha[j + 1] = pritha[j];
			holePosition = j;
		}

		pritha[holePosition] = holePositionValue;
		
		// if (holePositionValue != pritha[i]) {
		// 	pritha[holePosition] = holePositionValue;
		// }
	}

	// display the sorted array
	cout << "Ascending order" << endl;
	for (int i = 0; i < n; ++i) {
		cout << pritha[i] << " ";
	}
	cout << endl << endl;

	// decending
	for (int i = 1; i < n; ++i) {
		int holePosition = i;
		int holePositionValue = pritha[i];

		for (int j = i - 1; j >= 0 && pritha[j] < holePositionValue; --j) {
			pritha[j + 1] = pritha[j];
			holePosition = j;
		}

		pritha[holePosition] = holePositionValue;
		
		// if (holePositionValue != pritha[i]) {
		// 	pritha[holePosition] = holePositionValue;
		// }
	}

	// display the sorted array
	cout << "Decending order" << endl;
	for (int i = 0; i < n; ++i) {
		cout << pritha[i] << " ";
	}
	cout << endl;

	return 0;
}