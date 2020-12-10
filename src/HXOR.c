#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

void log_debug(char* fmt, ...) {
	#ifdef DEBUG
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
	#endif
}

int MSB(int x) {
	return 1 << (int)(log2(x));
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t-- > 0) {
		int n, x;
		scanf("%d %d", &n, &x);
		int A[n];

		for (int i=0; i<n; i++) scanf("%d ", &A[i]);

		int nops = 0;
		int i = 0;
		while (nops < x) {
			if (A[i] == 0) {
				i++;
				continue;
			}
			int p2 = MSB(A[i]);
			log_debug("MSB of %d is %d\n", A[i], p2);
			A[i] ^= p2;
			int j=i+1;
			while (j<n-1 && (A[j]^p2) >= A[j]) j++;
			if (j < n) A[j] ^= p2;
			nops++;
		}

		for (int i=0; i<n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	return 0;
}
