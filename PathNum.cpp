#include <iostream>
#include <iomanip>

using namespace std;

#define OBSTACLE -1

bool isValid(int matrix[8][8], int x, int y)
{
	return matrix[x][y] != OBSTACLE && x >= 0 && x < 8 && y >= 0 && y < 8;
}

void drawMatrix(int matrix[8][8])
{
	cout << "-------------------------" << endl;

	for (int i = 0; i < 8; i++) {
		cout << "|";
		for (int j = 0; j < 8; j++) {
			if (matrix[j][i] == OBSTACLE) {
				cout << "##|";
			} else {
				cout << setw(2) << matrix[j][i] << "|";
			}
		}
		cout << endl << "-------------------------" << endl;
	}
}

void fillMatrix(int matrix[8][8])
{
	for (int y = 7; y >= 0; y--) {
		for (int x = 7; x >= 0; x--) {
			if (!isValid(matrix, x, y)) { continue; }
			if (y == 7 && x == 7) {
				matrix[7][7] = 1;
			} else {
				int sum = 0;
				if (isValid(matrix, x + 1, y)) {
					sum += matrix[x + 1][y];
				}
				if (isValid(matrix, x, y + 1)) {
					sum += matrix[x][y+1];
				}
				matrix[x][y] = sum;
			}
		}
	}
}

int main()
{
	//Matrix [x][y]
	int field[8][8] = { 0 };
	field[0][3] = OBSTACLE;
	field[1][6] = OBSTACLE;
	field[2][1] = OBSTACLE;
	field[2][3] = OBSTACLE;
	field[2][4] = OBSTACLE;
	field[3][5] = OBSTACLE;
	field[4][2] = OBSTACLE;
	field[4][5] = OBSTACLE;
	field[5][3] = OBSTACLE;
	field[5][6] = OBSTACLE;
	field[6][1] = OBSTACLE;
	field[6][5] = OBSTACLE;

	fillMatrix(field);
	drawMatrix(field);

	cin.get();

	return 0;
}