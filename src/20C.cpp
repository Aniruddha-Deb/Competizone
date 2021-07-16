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
	int n,e;
	cin >> n >> e;
	vector<vector<pi>> G(n+1,vector<pi>());
	rep(i,0,e) {
		int a, b, l;
		cin >> a >> b >> l;
		G[a].push_back({b,l});
		G[b].push_back({a,l});
	}

	// dijkstra on a sparse tree here....
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	vi D(n+1,MOD);
	D[1] = 0;
	Q.push({0,1});
	vi pred(n+1,-1);

	while (!Q.empty()) {
		int v = Q.top().second;
		int d_v = Q.top().first;
		Q.pop();
		if (d_v != D[v]) continue;

		for (auto e : G[v]) {
			// wtf codeforces
			int to = e.first;
			int l = e.second;
			if (D[v]+l < D[to]) {
				D[to] = D[v]+l;
				pred[to] = v;
				Q.push({D[to], to});
			}
		}
	}

	if (D[n] == MOD) cout << "-1" << endl;
	else {
		vi s;
		int k = n;
		while (k != -1) {
			s.push_back(k);
			k = pred[k];
		}
		for(int i=s.size()-1; i>=0; i--) {
			cout << s[i] << " ";
		}
		cout << endl;
	}
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