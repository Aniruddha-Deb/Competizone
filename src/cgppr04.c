#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <string.h>

long mpp(int *A, int n, int k) {
	if (n == 1) return 0;
	if (k == 1) {
		long pp = 0;
		for (int i=0; i<n; i++) {
			for (int j=i-1; j>=0; j--) {
				if (A[j] > A[i]) pp += A[j];
			}
		}
		return pp;
	}
	long ans = LONG_MAX;
	for (int i=0; i<n; i++) {
		long cv = mpp(A, i+1, k-1) + mpp(A+i+1, n-(i+1), k-1);
		if (cv < ans) ans = cv;
	}
	return ans;
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
		
		printf("%ld\n", mpp(A, n, k));
	}
	return 0;
}
