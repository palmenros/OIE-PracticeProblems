#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int abs(int n)
{
	return n > 0 ? n : -n;
}

int maximumSubArraySum(const vector<int>& v)
{
	int maxSumSoFar = v[0];
	int maxSumUntilEnding = maxSumSoFar;

	for (int i = 1; i < v.size(); i++) {
		maxSumUntilEnding = max(v[i], maxSumUntilEnding + v[i]);
		maxSumSoFar = max(maxSumSoFar, maxSumUntilEnding);
	}
	
	return maxSumSoFar;
}

int minimumAbsSubArraySum(const vector<int>& v)
{
	int minSumSoFar = abs(v[0]);
	int minSumUntilHere = v[0];

	for (int i = 1; i < v.size(); i++) {
		minSumUntilHere = minSumUntilHere + v[i];
		if (abs(v[i]) < abs(minSumUntilHere)) {
			minSumUntilHere = v[i];
		}
		minSumSoFar = min(minSumSoFar, abs(minSumUntilHere));
	}
	return minSumSoFar;
}

int main()
{
	int n;
	while (cin >> n) {
		vector<int> v;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		cout << minimumAbsSubArraySum(v) << endl;
		v.clear();
	}
	return 0;
}