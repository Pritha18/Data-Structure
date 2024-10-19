#include <iostream>
using namespace std;

template <size_t row, size_t col>
void printMatrix(int (&matrix)[row][col]) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}


int main(int argc, char const *argv[])
{
	const int row = 5, col = 5;
	int mat[row][col];

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			mat[i][j] = j;
		}
	}

	printMatrix(mat);
	
	return 0;
}