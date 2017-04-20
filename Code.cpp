#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> digits;
map<pair<int, int>, long long> dp;

long long combinations(int first, int last)
{
	if(dp.find(make_pair(first, last)) != dp.end()){
		return dp[make_pair(first, last)];
	}
	
	long long result = 0;

	if (last <= first) {
		result = 1;
	} else {
		int i = digits[last - 1] * 10 + digits[last];
		if (digits[last - 1] == 0) {
			result = combinations(first, last - 1);
		} else if (digits[last] == 0) {
			result = combinations(first, last - 2);
		} else if ( i > 9 && i <= 26) {
			result = combinations(first, last - 1) + combinations(first, last - 2);
		} else {
			result = combinations(first, last - 1);
			
		}
	}

	dp[make_pair(first, last)] = result;
	return result;

}

int main(){
	string s;
	while (cin >> s) {
		if (s == "0") {
			return 0;
		}

		for (char c : s) {
			digits.push_back(atoi(string(1, c).c_str()));
		}
		try {
			cout << combinations(0, digits.size() - 1) << endl;
		} catch (exception& e) {
			cout << 0 << endl;
		}

		digits.clear();
		dp.clear();

	}
	return 0;
}