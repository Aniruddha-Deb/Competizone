#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

int find_belt(int **A, bool **B, int r, int c, int i, int j) {
	int blen = 0;
	if (i<0 || i>=r || j<0 || j>=c) return 0;
	else if (!B[i][j]) {
		B[i][j] = true;
		blen += A[i][j];
		if (A[i][j] == 1) {
			blen += find_belt(A, B, r, c, i+1, j+1);
			blen += find_belt(A, B, r, c, i+1, j);
			blen += find_belt(A, B, r, c, i+1, j-1);
			blen += find_belt(A, B, r, c, i, j-1);
			blen += find_belt(A, B, r, c, i-1, j-1);
			blen += find_belt(A, B, r, c, i-1, j);
			blen += find_belt(A, B, r, c, i-1, j+1);
			blen += find_belt(A, B, r, c, i, j+1);
		}
	}
	return blen;
}

int main() {
	int r, c;
	scanf("%d %d\n", &r, &c);
	int **A = malloc(sizeof(int*)*r);
	for (int i=0; i<r; i++)
		A[i] = malloc(sizeof(int)*c);

	bool **B = malloc(sizeof(bool*)*r);
	for (int i=0; i<r; i++) {
		B[i] = malloc(sizeof(bool)*c);
		memset(B[i], false, c);
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	int mlen = INT_MIN;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (!B[i][j] && A[i][j] == 1) {
				int len = find_belt(A, B, r, c, i, j);
				if (len > mlen) mlen = len;
			}
		}
	}
	printf("%d\n", mlen);
	return 0;
}
