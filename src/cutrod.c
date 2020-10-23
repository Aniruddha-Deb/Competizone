#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define LEN 100

int memo[LEN];

int cut_rod(int k, int nlen, int *lengths[2]) {
	if (k == 0) return 0;
	int q;
	for (int i=0; i<nlen; i++) {
		q = lengths[

int main() {
	int t;
	scanf("%d\n", t);
	int *lengths[2] = malloc(sizeof(int)*t);
	for (int i=0; i<t; i++) {
		scanf("%d %d\n", &lengths[i][0], $lengths[i][1]);
	}

	int n, k;
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
		scanf("%d\n", &k);
		printf("%d\n", cut_rod(k, t, lengths));
	}
	return 0;
}
