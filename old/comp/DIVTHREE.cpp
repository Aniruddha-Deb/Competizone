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

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k, d;
		cin >> n >> k >> d;
		int s = 0;
		for (int i=0; i<n; i++) {
			int u;
			cin >> u;
			s += u;
		}
		if (d < (s/k)) cout << d << endl;
		else cout << s/k << endl;
	}
	return 0;
}
