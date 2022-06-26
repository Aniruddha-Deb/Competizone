#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vi A(n);
	bool valid = false;
	rep(i,0,n) {
		cin >> A[i];
		if (A[i] == 1) valid = true;
	}

	if (!valid) {
		cout << 0 << endl;
		return;
	}

	ll sc = 0;
	ll esc = 0;
	ll tp = 1;
	rep(i,0,n) {
		if (A[i] == 1) {
			if (sc % k == 0 && sc > 0) {
				tp = (tp%MOD)*(esc%MOD);
				tp %= MOD;
				esc = 0;
			}
			sc++;
		}

		if (sc % k == 0 && sc > 0) esc++;
	}

	cout << tp << endl;
}

int main() {
	init();
	int t = 1;
	// cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}
