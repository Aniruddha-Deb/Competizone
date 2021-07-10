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
	int n, x;
	cin >> n >> x;
	ll sum = 0;
	rep(i,0,n) {
		int t;
		cin >> t;
		if (i%2 != 0) sum += t-1;
		else sum += t;
	}
	if (sum <= x) cout << "Yes" << endl;
	else cout << "No" << endl;
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