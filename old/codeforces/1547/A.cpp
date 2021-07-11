#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int xa, ya, xb, yb, xf, yf;
	cin >> xa >> ya >> xb >> yb >> xf >> yf;
	if ((xa == xb && xb == xf && abs(yb-yf)+abs(yf-ya)==abs(yb-ya)) || (ya==yb && yb==yf && abs(xb-xf)+abs(xf-xa)==abs(xb-xa))) {
		cout << abs(xa-xb) + abs(ya-yb) + 2 << endl;
	}
	else {
		cout << abs(xa-xb) + abs(ya-yb) << endl;		
	}
}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}