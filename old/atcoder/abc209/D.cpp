#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 100005
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

vi G[MAX];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void dfs(int s, vector<bool>& visited, vector<int>& colors, int cc) {
	visited[s] = true;
	colors[s] = cc;
	for (int n : G[s]) {
		if (!visited[n]) {
			dfs(n,visited,colors,cc^1);
		}
	}
}

void solve() {
	int n, q;
	cin >> n >> q;
	rep(i,0,n-1) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<bool> V(n+1, false);
	vi C(n+1,0);
	dfs(1,V,C,0);
	rep(i,0,q) {
		int c, d;
		cin >> c >> d;
		int delta = C[c] - C[d];
		if (delta == 0) cout << "Town" << endl;
		else cout << "Road" << endl;
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