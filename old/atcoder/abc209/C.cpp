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
	int n;
	cin >> n;
	vi C(n);
	rep(i,0,n) cin >> C[i];
	sort(C.begin(), C.end());
	ll ans = 1;
	for (int i=0; i<n; i++) {
		ll t = C[i];
		if (t-i <= 0) {
			ans = 0;
			break;
		}
		ans = ((ans%MOD)*((t-i)%MOD))%MOD;
	}
	cout << ans%MOD << endl;
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}