#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	long long tmp;

	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp % b;
	}

	return a;
}

long long lcm(long long a, long long b)
{
	return (a / gcd(a, b))*b;
}

int main()
{
	long long a, b;
	while (cin >> a >> b) {
		cout << "MCD: " << gcd(a, b) << "; MCM: " << lcm(a, b) << endl;
	}
}