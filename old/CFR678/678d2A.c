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
		int n, m, temp;
		scanf("%d %d\n", &n, &m);
		long sum = 0;
		for (int i=0; i<n; i++) {
			scanf("%d", &temp);
			sum += temp;
		}
		if (sum == m) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
