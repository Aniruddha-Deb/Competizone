#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t-- > 0) {
		int n;
		scanf("%d\n", &n);
		int *A = malloc(sizeof(int)*n);
		for (int i=0; i<n; i++) {
			scanf("%d ", &A[i]);
		}
		qsort(A, n, sizeof(int), &cmpfunc);
		if (n == 1) {
			printf("%d\n", A[0]);
		}
		else if (n == 2) {
			printf("%d\n", A[1]);
		}
		else if (n == 3) {
			printf("%d\n", A[0]+A[1] > A[2] ? A[0]+A[1] : A[2]);
		}
		else {
			int l3s = A[0]+A[1]+A[2] > A[3] ? A[0]+A[1]+A[2] : A[3];
			int l2s = A[3]+A[0] > A[1]+A[2] ? A[3]+A[0] : A[1]+A[2];
			printf("%d\n", l3s > l2s ? l2s : l3s);
		}
	}
	return 0;
}
