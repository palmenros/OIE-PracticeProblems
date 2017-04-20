#include <iostream>
#include <string>
#include <vector>

std::vector<long long> primes = { 2, 3 };

bool isPrime(long long n)
{
	for (unsigned int i = 0; primes[i] * primes[i] <= n; i++) {
		if (n % primes[i] == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	for (int i = 1; i < 1000000 / 6; i++) {
		if (isPrime(6 * i + 1)) {
			primes.push_back(6 * i + 1);
		}
		if (isPrime(6 * i - 1)) {
			primes.push_back(6 * i - 1);
		}
	}

	long long n;
	while (std::cin >> n){
		std::cout << (isPrime(n) ? "ES PRIMO" : "NO ES PRIMO") << std::endl;
	}

	std::cin.get();
	return 0;
}