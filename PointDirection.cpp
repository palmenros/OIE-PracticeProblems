#include <iostream>

using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}

	Point operator-(const Point& other)
	{
		return Point(x - other.x, y - other.y);
	}
};

double crossProduct(const Point& a, const Point& b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{

	double px, py, rx1, rx2, ry1, ry2;
	while (cin >> px >> py >> rx1 >> ry1 >> rx2 >> ry2) {
		Point p(px, py);
		Point r1(rx1, ry1);
		Point r2(rx2, ry2);

		double val = crossProduct(r2 - r1, p - r1);

		if (val == 0) {
			cout << "EN LA LINEA" << endl;
		} else if (val > 0) {
			cout << "IZQUIERDA" << endl;
		} else {
			cout << "DERECHA" << endl;
		}

	}


}