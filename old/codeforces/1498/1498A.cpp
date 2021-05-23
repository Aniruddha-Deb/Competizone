#include <bits/stdc++.h>
using namespace std;

int** intMatrix(int n, int m) {
	int **A = (int**)malloc(sizeof(int*)*n);
	for (int i=0; i<n; i++) {
		A[i] = (int*)malloc(sizeof(int)*m);
	}
	return A;
}

void destroy_intMatrix(int **A, int n, int m) {
	for (int i=0; i<n; i++) {
		free(A[i]);
	}
	free(A);
}

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

long gcd(long a, long b) { 
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		long n;
		cin >> n;
		long k = n;
		long sum = 0;
		while (k > 0) {
			sum += k%10;
			k /= 10;
		}
		if (n%2 == 0 && sum%2 == 0) {
			cout << n << endl;
			continue;
		}
		if (gcd(n,sum) > 1) {
			cout << n << endl;
			continue;
		}
		while (gcd(n,sum) <= 1) {
			if (n%10 == 9) {
				k = n;
				while (k%10 == 9) {
					sum -= 9;
					k /= 10;
				}
				sum++;
			}
			else sum++;
			n++;
		}
		cout << n << endl;
	}
	return 0;
}
