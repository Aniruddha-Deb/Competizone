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
		int n;
		cin >> n;
		int *A = (int*)malloc(sizeof(int)*(n+5));
		memset(A, 0, (n+5)*sizeof(int));
		int min = INT_MAX;
		int max = INT_MIN;
		for (int i=0; i<n; i++) {
			int k;
			cin >> k;
			if (k < min) min = k;
			if (k > max) max = k;
			A[k]++;
		}
	
		long ntups = 0;
		if (min == max) ntups += A[min]*(A[min]-1)*(A[min]-2)/6;
		else if (min == max-1) {
			long sum = A[min] + A[min+1];
			ntups += sum*(sum-1)*(sum-2)/6;
		}
		for (int i=min; i<=max-2; i++) {
			long sum = A[i] + A[i+1] + A[i+2];
			ntups += (sum*(sum-1)*(sum-2)/6);
			if (i > min) {
				long ssum = A[i]+A[i+1];
				ntups -= (ssum*(ssum-1)*(ssum-2)/6);
			}
		}
		free(A);
		cout << ntups << endl;
	}
	return 0;
}
