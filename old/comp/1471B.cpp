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
		int n, x;
		cin >> n >> x;
		vector<int> A;
		int k;
		long sum = 0;
		for (int i=0; i<n; i++) {
			cin >> k;
			A.push_back(k);
		}

		int i = 0;
		while (i < A.size() && A[i]%x == 0) {
			for (int j=0; j<x; j++) {
				A.push_back(A[i]/x);
			}
			i++;
		}

		for (i=0; i<A.size(); i++) {
			sum += A[i];
		}

		cout << sum << endl;
	}
	return 0;
}
