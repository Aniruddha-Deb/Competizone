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
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> G(n+1,vector<pair<int,int>>());

	rep (i,0,n-1) {
		int u, v, l;
		cin >> u >> v >> l;
		G[u].push_back({v,l});
		G[v].push_back({u,l});
	}

	vector<ll> vals(n+1,0);
	vector<int> costs(n+1,0);
	vector<bool> visited(n+1,false);
	vector<bool> isLeaf(n+1,false);
	stack<int> S;
	S.push(1);
	visited[1] = true;
	while (!S.empty()) {
		int u = S.top();
		S.pop();
		int n_unvis = 0;
		for (auto e : G[u]) {
			int v = e.first;
			int l = e.second;
			if (!visited[v]) {
				S.push(v);
				n_unvis++;
				costs[v] = costs[u] + l;
				vals[v] = vals[u] + costs[v];
				visited[v] = true;
			}
		}

		if (n_unvis == 0) isLeaf[u] = true;
	}

	ll minLeafVal = LLONG_MAX;
	for (int i=1; i<=n; i++) {
		if (isLeaf[i]) {
			//cout << vals[i] << " ";
			if (vals[i] < minLeafVal) minLeafVal = vals[i];
		} 
	}
	//cout << endl;

	cout << minLeafVal << endl;

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
