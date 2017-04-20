#include <iostream>
#include <vector>

using namespace std;

void printIntersection(const vector<int>& a, const vector<int>& b)
{
	int i = 0, j = 0;
	int sa = a.size(), sb = b.size();
	while (i < sa && j < sb) {
		int va = a[i], vb = b[j];
		if (va == vb) {
			cout << va << " ";
			i++;
			j++;
		} else if (va > vb) {
			j++;
		} else {
			i++;
		}
	}
	cout << endl;
}

void printUnion(const vector<int>& a, const vector<int>& b)
{
	int i = 0, j = 0;
	int sa = a.size(), sb = b.size();
	while (i < sa && j < sb) {
		int va = a[i], vb = b[j];
		if (va == vb) {
			cout << va << " ";
			i++;
			j++;
		} else if (va > vb) {
			cout << vb << " ";
			j++;
		} else {
			cout << va << " ";
			i++;
		}
	}

	while (i < sa) {
		cout << a[i++] << " ";
	}

	while (j < sb) {
		cout << b[j++] << " ";
	}

	cout << endl;
}



int main()
{
	vector<int> a = { 1, 2, 4, 5, 6 };
	vector<int> b = { 2, 3, 5, 7 };
	printIntersection(a, b);
	printIntersection(b, a);
	printUnion(a, b);
	printUnion(b, a);

	cin.get();
	return 0;
}