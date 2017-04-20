#include <iostream>

long long fib(int n)
{
	if (n <= 0) { return 0; }
	long long l1 = 0, l2 = 1;
	for (int i = 2; i < n; i++) {
		long long tmp = l2;
		l2 = l1 + l2;
		l1 = tmp;
	}
	return l1 + l2;
}

int main()
{
	int tmp;
	while (std::cin >> tmp) {
		std::cout << fib(tmp) << std::endl ;
	}
	return 0;
}