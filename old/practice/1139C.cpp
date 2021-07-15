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

int mod(int x) {
	x = x%MOD;
    if (x < 0) x += MOD;
    return x;
}

int modexp(int n, int k) {
	// k < 100, so modular exponentiation not required
	ll exp = 1;
	rep(i,0,k) {
		exp = (exp*n)%MOD;
	}
	return exp%MOD;
}

int dfs(vector<vi>& G, vector<bool>& visited, int root) {
	visited[root] = true;
	int ctr = 1;
	for (int i : G[root]) {
		if (!visited[i]) {
			ctr += dfs(G,visited,i);
		}
	}
	return ctr;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vi> G(n+1,vi());
	rep(i,0,n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0) {
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}

	vector<bool> visited(n+1, false);
	int ans = modexp(n,k);
	rep(i,1,n+1) {
		if (!visited[i]) {
			int len = dfs(G,visited,i);
			ans = mod(ans-modexp(len,k));
		}
	}

	cout << ans << endl;

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