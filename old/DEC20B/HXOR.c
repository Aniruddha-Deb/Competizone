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

int main() {
	int t;
	scanf("%d\n", &t);
	while (t-- > 0) {
		int n, x;
		scanf("%d %d", &n, &x);
		int A[n];

		for (int i=0; i<n; i++) {
			scanf("%d ", &A[i]);
		}

		int nops = 0;
		for (int i=0; i<n-1; i++) {
			if (nops >= x) break;
			
			for (int j=30; j>=0; j--) {
				if (nops >= x) break;
				if ((1<<j) & A[i]) {
					bool hit = false;
					for (int k=i+1; k<n; k++) {
						if ((1<<j) & A[k]) {
							A[i] ^= (1<<j);
							A[k] ^= (1<<j);
							nops++;
							hit = true;
							break;
						}
					}
					if (!hit) {
						A[i] ^= (1<<j);
						A[n-1] ^= (1<<j);
						nops++;
					}
				}
			}
		}

		if (nops < x) {
			if (n == 2 && (x-nops)%2 == 1) {
				A[n-2] ^= 1;
				A[n-1] ^= 1;
			}
		}

		for (int i=0; i<n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	return 0;
}
