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
		int n, d;
		scanf("%d %d", &n, &d);
		int a[n];
		double risk = 0;
		for (int i=0; i<n; i++) {
			scanf("%d ", &a[i]);
			if (a[i] >= 80 || a[i] <= 9) risk++;
		}
		double norisk = n - risk;
		int ans = ceil(risk/d) + ceil(norisk/d);
		printf("%d\n", ans);

	}
	return 0;
}
