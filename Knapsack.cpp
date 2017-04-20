#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> weights;
vector<int> values;

//peso, numero
map<pair<int, int>, int> dp;

int max(int a, int b) { return a > b ? a : b; }

int knapsack(int w, int n)
{
	if (n < 0 || w <= 0) {
		return 0;
	}

	if (dp.find(make_pair(w, n)) != dp.end()) {
		return dp[make_pair(w, n)];
	}

	int val;

	if (weights[n] > w) {
		val =  knapsack(w, n - 1);
	} else {
		val = max(knapsack(w - weights[n], n - 1) + values[n], knapsack(w, n - 1));
	}

	dp[make_pair(w, n)] = val;
	return val;
}

int main()
{
	int n, w;
	while (cin >> n >> w) {
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			values.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			weights.push_back(tmp);
		}

		cout << knapsack(w, n - 1) << endl;

		weights.clear();
		values.clear();
		dp.clear();
	}

}