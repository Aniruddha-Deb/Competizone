#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main() {
	int t;
	scanf("%d\n", &t);
	while (t-- > 0) {
		int n;
		scanf("%d\n", &n);
		int *A = malloc(sizeof(int)*n);
		int *B = malloc(sizeof(int)*n);
		int *C = malloc(sizeof(int)*n);
		for (int i=0; i<n; i++) {
			B[i] = -1;
			C[i] = 0;
		}
		for (int i=0; i<n; i++) {
			scanf("%d", &A[i]);
			C[A[i]]++;
		}
		int k = 2;
		for (int i=n-1; i>=0; i--) {
			if (B[i] == -1) {
				B[i] = k;
				C[A[i]]--;
				for (int j=i-1; j>=0 && C[A[i]] > 0; j--) {
					if (A[j] == A[i]) {
						C[A[i]]--;
						B[j] = k;
					}
				}
				k++;
			}
		}
		for (int i=0; i<n; i++) {
			printf("%d ", B[i]);
		}
		printf("\n");
		free(A);
		free(B);
		free(C);
	}
	return 0;
}
