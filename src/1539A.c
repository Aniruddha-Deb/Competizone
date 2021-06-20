#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef long long ll;

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
		int n, x, t;
	}
	return 0;
}
