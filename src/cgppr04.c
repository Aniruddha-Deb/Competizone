#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <string.h>

long mpp(int *A, int n, int si, int ei, int k, long *lookup) {
	if (n == 1) return 0;
	if (k == 1) return lookup[si*n + ei];
	long ans = LONG_MAX;
	for (int i=si; i<=ei; i++) {
		long cv = mpp(A, n, si, i, k-1, lookup) + mpp(A, n, i+1, ei, k-1, lookup);
		if (cv < ans) {
			ans = cv;
		}
	}
	return ans;
}

long* calc_ppt(int n, int *A) {
	long *ppt = malloc(n*n*sizeof(long));
	for (int i=0; i<n; i++) {
		for (int k=0; k<i; k++) {
			for (int l=i; l>k; l--) {
				for (int j=l-1; j>=k; j--) {
					if (A[j] > A[l]) ppt[k*n + i] += A[j];
				}
			}
		}
	}

	return ppt;
}

void print_ppt(long *ppt, int n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("%ld ", ppt[j*n + i]);
		}
		printf("\n");
	}
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t-- > 0) {
		int n, k;
		scanf("%d %d\n", &n, &k);
		int *A = malloc(sizeof(int)*n);
		for (int i=0; i<n; i++) {
			scanf("%d", &A[i]);
		}

		long *ppt = calc_ppt(n, A);	
		//print_ppt(ppt, n);
		printf("%ld\n", mpp(A, n, 0, n-1, k, ppt));
	}
	return 0;
}
