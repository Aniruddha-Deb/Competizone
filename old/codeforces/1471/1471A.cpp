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
		vector<int> A(n);
		double maxb = 0;
		double minb = 0;
		for (int i=0; i<n; i++) {
			cin >> A[i];
			maxb += A[i];
			minb += round(((double)A[i])/x);
		}

		maxb = round(maxb/x);
		if (maxb > minb) cout << minb << " " << maxb << endl;
		else cout << maxb << " " << minb << endl;
	}
	return 0;
}
