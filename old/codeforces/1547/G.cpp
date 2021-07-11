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

void dfs(int r, vector<vi>& G, vi& paths, vi& loops, vector<bool>& trav, int depth) {
	if (paths[r]+1 > G[r].size())
	paths[r]++;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vi> G(n+1,vi());
	vi paths(n+1,0);
	vector<bool> traversed(n+1,false);
	vi loops(n+1,0);
	rep(i,0,m) {
		int a, b;
		cin >> a >> b;
		if (a == b) loops[a] = 1;
		else G[a].push_back(b);
	}

	dfs(1,G,paths,loops,traversed);

	for (int i=1; i<=n; i++) {
		cout << traversed[i] << " ";
	}
	cout << endl;
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