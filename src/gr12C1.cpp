#include <bits/stdc++.h>
using namespace std;

const int N = 305;
string A[N];

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
		int n;
		cin >> n;

		int sum[3] = {0, 0, 0};

		for (int i=0; i<n; i++) {
			cin >> A[i];
			for (int j=0; j<n; j++) {
				if (A[i][j] == 'X') {
					sum[(i+j)%3]++;
				}
			}
		}

		int idx = min_element(sum, sum+3) - sum;

		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if ((i+j)%3 == idx && A[i][j] == 'X') {
					A[i][j] = 'O';
				}
			}
		}

		for (int i=0; i<n; i++) {
			cout << A[i] << endl;
		}
	}
	return 0;
}
