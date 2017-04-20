#include <iostream>
#include <cmath>

using namespace std;

enum Direction : char {
	LEFT = 0,
	RIGHT = 1,
	COLINEAR = 2
};

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y (y) {}
	Point() : x(0), y(0) {}

	Point operator-(const Point& other) const
	{
		return Point(x - other.x, y - other.y);
	}
};

istream& operator>>(istream& is, Point& p)
{
	is >> p.x >> p.y;
	return is;
}

double crossProduct(const Point& a, const Point& b)
{
	return a.x * b.y - a.y * b.x;
}

Direction getDirection(const Point& p, const Point& r1, const Point& r2)
{
	double cp = crossProduct(r2 - r1, p - r1);
	if (cp == 0) {
		return COLINEAR;
	} else if (cp > 0) {
		return LEFT;
	} else {
		return RIGHT;
	}
}

bool validDirection(Direction a, Direction b)
{
	return a == COLINEAR || b == COLINEAR || (a + b == 1);
}

bool segmentsIntersect(const Point& a, const Point& b, const Point& c, const Point& d)
{
	Direction d1, d2, d3, d4;
	d1 = getDirection(a, c, d);
	d2 = getDirection(b, c, d);
	d3 = getDirection(c, a, b);
	d4 = getDirection(d, a, b);
	if (d1 == COLINEAR && d1 == COLINEAR && d1 == COLINEAR && d1 == COLINEAR) {
		double ab, cd, ac, ad, bc, bd;
		if (a.x == b.x && b.x == c.x && c.x == d.x) {
			//Line is vertical
			ab = fabs(b.y - a.y);
			cd = fabs(d.y - c.y);
			ac = fabs(c.y - a.y);
			ad = fabs(d.y - a.y);
			bc = fabs(c.y - b.y);
			bd = fabs(d.y - b.y);
		} else {
			//Line is horizontal
			ab = fabs(b.x - a.x);
			cd = fabs(d.x - c.x);
			ac = fabs(c.x - a.x);
			ad = fabs(d.x - a.x);
			bc = fabs(c.x - b.x);
			bd = fabs(d.x - b.x);
		}
		return 2 * (ab + cd) >= ad + ac + bd + bc;
	}
	bool ca = validDirection(d1, d2);
	bool cb = validDirection(d3, d4);
	return ca && cb;
}

bool getPoints(Point& a, Point& b, Point& c, Point& d)
{
	bool res = true;
	cout << "A: ";
	res &= (bool)(cin >> a);
	cout << "B: ";
	res &= (bool)(cin >> b);
	cout << "C: ";
	res &= (bool)(cin >> c);
	cout << "D: ";
	res &= (bool)(cin >> d);

	return res;
}

int main()
{
	cout << "USO:" << endl;
	cout << "Introducir en orden los puntos A, B, C, D, uno en cada linea, en la forma PX PY, separados por un espacio" << endl << endl;
	Point a, b, c, d;
	while (getPoints(a, b, c, d)) {
		cout << (segmentsIntersect(a, b, c, d) ? "INTERSECAN" : "NO INTERSECAN") << endl << endl;
	}

	cin.ignore();
	cin.get();
	return 0;
}