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
		int a, b;
		scanf("%d %d", &a, &b);
		long nae = a/2;
		long nao = a - nae;
		long nbe = b/2;
		long nbo = b - nbe;
		long ans = nae*nbe + nao*nbo;
		printf("%ld\n", ans);
	}
	return 0;
}
