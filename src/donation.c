#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MOD 1000000007

int fac[] = {1, 1, 2, 6, 24, 120, 720};

int factorial(int n) {
	if (n <= 6) return fac[n]; 
	return ((n%MOD) * (factorial(n-1)%MOD))%MOD;
}

int binom(int n, int k) {
	return (factorial(n) / (factorial(k) * factorial(n-k))) % MOD;
}

int power(int n, int p) {
	if (n == 1 || p == 0) return 1;
	return ((n%MOD) * (power(n,p-1)%MOD))%MOD;
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t-- > 0) {
		int n, c, m;
		scanf("%d %d %d\n", &n, &c, &m);
		int sum = 0;
		int mul = 1;
		for (int i=c; i>0; i--) {
			sum = (sum % MOD) + mul*((power(i, n-c*(m-1))*binom(c, c-i))%MOD);
			mul *= -1;
			printf("Sum is now %d\n", sum);
		}
		if (m == 1) {
			sum = ((sum%MOD) / factorial(c)) % MOD;
		}
		else if (m == 2) {
			sum = ((sum%MOD) * binom(n, c) / factorial(c)) % MOD;
		}
		else if (m == 3) {
			sum = ((sum%MOD) * factorial(n) / (power(factorial(c), 3)*2)) % MOD;
		}
		printf("%d\n", sum);
	}
	return 0;
}
