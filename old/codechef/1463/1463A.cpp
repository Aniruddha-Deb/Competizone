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
		int s = 0;
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		s = (n1 + n2 + n3);
		if (s%7 == 2 && n1 >= (s/7) && n2 >= (s/7) && n3 >= (s/7)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
