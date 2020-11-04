#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

int primes[] = {0, 1, 2, 3, 3, 5, 5, 7, 7, 7, 7, 11, 11, 13, 13, 13, 13, 17, 17, 19, 19, 19, 19, 23, 23, 23, 23, 23, 23, 29, 29, 31, 31, 31, 31, 31, 31, 37, 37, 37, 37, 41, 41, 43, 43, 43, 43, 47, 47, 47, 47, 47, 47, 53, 53, 53, 53, 53, 53, 59, 59, 61, 61, 61, 61, 61, 61, 67, 67, 67, 67, 71, 71, 73, 73, 73, 73, 73, 73, 79, 79, 79, 79, 83, 83, 83, 83, 83, 83, 89, 89, 89, 89, 89, 89, 89, 89, 97, 97, 97, 97 };

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		int nz = n-primes[n];
		for (int i=0; i<n; i++) {
			int zc = 0;
			for (int j=0; j<n; j++) {
				if (zc < nz && (j >= i || j < (i-primes[n]))) {
					cout << "0 ";
					zc++;
				}
				else cout << "1 ";
			}
			cout << endl;
		}
	}
	return 0;
}
