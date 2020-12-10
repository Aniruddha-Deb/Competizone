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
		int n, k;
		scanf("%d %d", &n, &k);
		
		int A[n];
		int nneg = n-k;
		for (int i=1; i<=n; i++) {
			A[i-1] = i;
			if (nneg > 0 && i%2 == 1) {
				A[i-1] = -i;
				nneg--;
			}
		}

		if (nneg > 0) {
			for (int i=n-1; i>=0; i--) {
				if (nneg > 0 && A[i] > 0) {
					A[i] *= -1;
					nneg--;
				}
			}
		}
		
		for (int i=0; i<n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	return 0;
}
