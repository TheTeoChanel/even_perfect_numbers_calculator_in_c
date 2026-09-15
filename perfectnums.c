#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(unsigned long long n);
unsigned long long exponent(unsigned long long x, unsigned long long y);

int main() {
	int perfectIndex = 0;
	unsigned long long p = 1;
	unsigned long long number = 1;
	int toCalculate = 8;

	while (toCalculate >= 1) {
		do {p++;}
		while (!isPrime(p));

		if (isPrime(exponent(2, p) - 1)) {
			number = exponent(2, p - 1) * (exponent(2, p) - 1);
			perfectIndex++;
			printf("%d. perfect number is %llu. Mersene prime is ", perfectIndex, number);
			printf("%llu.\n", p);
			toCalculate--;
		}
	}
	return 0;
}

bool isPrime(unsigned long long n) {
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	for (unsigned long long i = 2; i <= ((unsigned long long)sqrt(n))+1; i++) {
		if (n % i == 0)
			return false;
		if (i == ((unsigned long long)sqrt(n))+1)
			return true;
	}
	return false;
}

unsigned long long exponent(unsigned long long x, unsigned long long y) {
	unsigned long long res = x;
	for (unsigned long long i = 1; i < y; i++) {
		res *= x;
	}
	return res;
}