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

ll sum[200005];
int leaves[200005];
int ppl[200005];

void calc_attrs(int root, vector<vector<int>>& G) {
	if (G[root].empty()) {
		leaves[root] = 1;
		sum[root] = ppl[root];
		return;
	}
	for (int n : G[root]) {
		calc_attrs(n,G);
		sum[root] += sum[n];
		leaves[root] += leaves[n];
	}
	sum[root] += ppl[root];
}

ll maxsum(int root, vector<vector<int>>& G) {
	ll msum = ceil(((double)sum[root])/leaves[root]);
	for (int n : G[root]) {
		ll tmsum = maxsum(n,G);
		if (tmsum > msum) msum = tmsum;
	}
	return msum;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> G(n+1, vector<int>());
	for (int i=2; i<=n; i++) {
		int t;
		cin >> t;
		G[t].push_back(i);
	}
	for (int i=1; i<=n; i++) {
		cin >> ppl[i];
	}

	calc_attrs(1,G);

	ll msum = 0;
	for (int i=1; i<=n; i++) {
		ll tsum = ceil(((double)sum[i])/leaves[i]);
		if (tsum > msum) msum = tsum;
	}
	cout << msum << endl;
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
