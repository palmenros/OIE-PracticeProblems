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
	cout << endl;
}

int myMin(int a, int b)
{
	return a < b ? a : b;
}

void fillMatrix(int matrix[8][8])
{
	for (int y = 7; y >= 0; y--) {
		for (int x = 7; x >= 0; x--) {
			if (!isValid(matrix, x, y)) { continue; }
			if (y == 7 && x == 7) {
				matrix[7][7] = 0;
			} else {
				int min = -1;
				if (isValid(matrix, x + 1, y)) {
					min = matrix[x + 1][y] + 1;
				}
				if (isValid(matrix, x, y + 1)) {
					if (min == -1) {
						min = matrix[x][y + 1] + 1;
					} else {
						min = myMin(min, matrix[x][y + 1] + 1);
					}
				}
				matrix[x][y] = min;
			}
		}
	}
}

void writePath(int matrix[8][8])
{

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
	writePath(field);
	

	cin.get();

	return 0;
}