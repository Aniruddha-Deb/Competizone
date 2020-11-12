#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main() {
	int m, x;
	scanf("%d %d\n", &m, &x);
	int *n = malloc(sizeof(int)*m);
	int tot = 0;
	for (int i=0; i<m; i++) {
		scanf("%d\n", &n[i]);
		tot += n[i];
	}
	if (x >= tot) {
		printf("Sorry, we can only supply %d oranges\n", tot-1);
		for (int i=0; i<m-1; i++) {
			printf("%d %d %d\n", n[i], n[i], 0);
		}
		printf("%d %d %d\n", n[m-1], n[m-1]-1, 1);
	}
	else {
		printf("Thank you, your order for %d oranges are accepted\n", x);
		for (int i=0; i<m; i++) {
			if (x >= n[i]) {
				printf("%d %d %d\n", n[i], n[i], 0);
				x -= n[i];
			}
			else if (x > 0 && x < n[i]) {
				printf("%d %d %d\n", n[i], x, n[i]-x);
				x -= n[i];
			}
			else {
				printf("%d %d %d\n", n[i], 0, n[i]);
			}
		}
	}
	return 0;
}
