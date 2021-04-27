#include <bits/stdc++.h>

using namespace std;

int stack_size(int *A, int *s, int n, int k1, int k2) {
	if (k1 <= 0 && k2 <= 0) return 0;
	int msum = INT_MAX;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (j != i && s[i] == 0 && s[j] == 0) {
				int k = 0;
				int a1, a2;
				a1 = a2 = 0;
				if (k1 > 0) { k++; s[i] = 1; a1 = A[i]; }
				if (k2 > 0) { k++; s[j] = 1; a2 = A[j]; }
				int res = stack_size(A, s, n, k1-a1, k2-a2);
				if (res == INT_MAX || res == -1) goto cleanup;
				k += res;
				if (k < msum) msum = k;

				cleanup:
				if (k1 > 0) s[i] = 0;
				if (k2 > 0) s[j] = 0;
			}
		}
	}
	if (msum == INT_MAX) return -1;
	return msum;
}

int main(int argc, char** argv) {

	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n >> k;
		int *A = (int*)malloc(sizeof(int)*n);
		int *s = (int*)malloc(sizeof(int)*n);
		memset(s, 0, sizeof(int)*n);
		
		for (int i=0; i<n; i++) {
			cin >> A[i];
		}

		cout << stack_size(A, s, n, k, k) << endl;
		free(A);
		free(s);
	}

	return 0;
}
