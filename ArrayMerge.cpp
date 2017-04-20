#include <iostream>
#include <vector>

using namespace std;

int findIntersect(const vector<int>& a, const vector<int>& b)
{
	int asiz = a.size();
	int bsiz = b.size();
	int diff = asiz - bsiz;
	const vector<int>* big = &a;
	const vector<int>* small = &b;
	if (asiz < bsiz) {
		small = &a;
		big = &b;
		diff = bsiz - asiz;
	}

	int lastIndex = 0;

	for (int i = 0; i < small->size(); i++) {
		if (small->at(i) != big->at(diff + i)) {
			lastIndex = i;
		}
	}

	return lastIndex + 2;
}

int main()
{
	vector<int> a = {4, 51, 6, 1 ,6, 3, 62, 61, 8, 5, 16, 61, 61, 78, 2, 5,1};
	vector<int> b = {5, 4, 5, 6, 8, 5, 16, 61, 61, 78, 2, 5, 1};
	cout << findIntersect(b, a) << endl;
	
	cin.get();
}