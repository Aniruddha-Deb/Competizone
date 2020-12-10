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
		int nb, p;
		cin >> nb >> p;
		int **A = intMatrix(nb,2);
		int *N = (int*)malloc(sizeof(int)*nb);
		memset(N, 0, nb*sizeof(int));
	
		for (int i=0; i<nb; i++) {
			cin >> A[i][0] >> A[i][1];
		}

		bool doable = false;
		for (int i=0; i<nb; i++) {
			for (int j=0; j<nb; j++) {
				if (abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]) <= p) {
					N[i]++;
				}
			}
			if (N[i] == nb) {
				doable = true;
				break;
			}
		}
		if (doable) cout << 1 << endl;
		else cout << -1 << endl;

	}
	return 0;
}
