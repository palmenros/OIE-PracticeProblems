#include <iostream>
#include <map>
using namespace std;

map<long long, long long> dp;

int maxValue(long long n)
{
	if (dp.find(n) != dp.end()) { return dp[n]; }
	long long val = 0;
	if (n == 0) {
		val = 0;
	} else {
		long long hmax = maxValue(n / 2) + maxValue(n / 3) + maxValue(n / 4);
		if (hmax > n) {
			val = hmax;
		} else {
			val =  n;
		}
	}
	dp[n] = val;
	return val;
}

int main()
{
	long long tmp;
	while (cin >> tmp) {
		cout << maxValue(tmp) << endl;
		dp.clear();
	}
}
