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
		int k, n;
		cin >> k >> n;
		int fo, lo;
		fo = lo = -1;
		for (int i=0; i<n; i++) {
			int u;
			cin >> u;
			if (u == k && fo == -1) fo = i+1;
			if (u == k) lo = i+1;
		}
		if (fo == lo) cout << -1 << endl;
		else cout << fo << " " << lo << endl;
	}
	return 0;
}
