#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main() {
	int d1, v1, d2, v2, p;
	scanf("%d %d %d %d %d", &d1, &v1, &d2, &v2, &p);

	int nvac = 0, i=0;
	while (nvac < p) {
		i++;
		if (d1 <= i) nvac += v1;
		if (d2 <= i) nvac += v2;
	}
	printf("%d\n", i);
	return 0;
}
