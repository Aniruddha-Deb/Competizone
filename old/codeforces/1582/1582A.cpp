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
	int a, b, c;
	cin >> a >> b >> c;
	int delta = 0;
	if (c%2 == 0) delta = 0;
	else delta = 3;
	if (b%2 == 0 && delta == 3) delta = 1;
	else if (b%2 == 0 && delta == 0) delta = 0;
	else if (b%2 != 0 && delta == 3) delta = 1;
	else delta = 2;

	if (a-delta >= 0) cout << (a-delta)%2 << endl;
	else cout << delta-a << endl;
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
