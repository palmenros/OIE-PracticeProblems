#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
};

double crossProduct(const Point& a, const Point& b)
{
	return a.x * b.y - a.y * b.x;
}

double polygonArea(const vector<Point>& vertices)
{
	double sum = 0.;
	for (int i = 0; i < vertices.size(); i++) {
		sum += crossProduct(vertices[i], vertices[(i + 1) % vertices.size()]);
	}
	return abs(sum) / 2.0;
}

int main()
{
	
	int n;
	while (cin >> n) {
		vector<Point> vertices;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			vertices.push_back(Point(x, y));
		}

		cout << polygonArea(vertices) << endl;

	}

	return 0;
}