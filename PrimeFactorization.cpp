#include <iostream>
#include <vector>

using namespace std;

vector<long long> factorNumber(unsigned long long n)
{
	vector<long long> result;

	while (n % 2 == 0) {
		n /= 2;
		result.push_back(2);
	}

	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			n /= i;
			result.push_back(i);
		}
	}

	if (n != 1) {
		result.push_back(n);
	}

	return result;

}

void printFactors(const vector<long long>& v)
{
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}

int main()
{
	unsigned long long n;
	while (cin >> n) {
		printFactors(factorNumber(n));
	}

	return 0;
}