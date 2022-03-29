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
	vi ec(n+1,0);
	for (int i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;
		ec[u]++;
		ec[v]++;
	}
	for (int i=1; i<=n; i++) {
		if (ec[i] == n-1) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
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
