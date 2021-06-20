#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX 100001

typedef long long ll;

int t[4*MAX];

void build(char *a, int v, int tl, int tr) {
	if (tl == tr) {
        t[v] = a[tl]-'a'+1;
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int min(int a, int b) { return a>b?b:a; }
int max(int a, int b) { return a>b?a:b; }

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void log_debug(char* fmt, ...) {
	#ifdef DEBUG
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
	#endif
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	getchar();
	char s[MAX];
	fgets(s,n+1,stdin);
	build(s,1,0,n-1);
	while (q-- > 0) {
		int l, r;
		scanf("%d %d", &l, &r);
		ll ans = sum(1,0,n-1,l-1,r-1);
		printf("%lld\n", ans);
	}
	return 0;
}
