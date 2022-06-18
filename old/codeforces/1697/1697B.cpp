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
	int n, q;
	cin >> n >> q;
	vi P(n);
	rep(i,0,n) cin >> P[i];

	sort(P.begin(), P.end());
	vector<ll> S(n+1);
	S[0] = 0;
	rep(i,1,n+1) S[i] = S[i-1] + P[i-1];

	rep(t,0,q) {
		ll ms = 0;
		int x, y;
		cin >> x >> y;
		// cout << n-x+y-1 << " " << n-x-1 << endl;
		cout << S[n-x+y] - S[n-x] << endl;
	}
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
