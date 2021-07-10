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

void dfs(vi const (&G)[100005], vector<bool>& cc, vi& visited_stack, int k) {
	visited_stack.push_back(k);
	cc[k] = true;
	for (int i : G[k]) {
		if (!cc[i]) {
			dfs(G,cc,visited_stack,i);
		}
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	vi G[100005];
	rep(i,0,k) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<bool> cc(n+1, false);
	int ncc = 0;
	vi visited_stack;
	for (int i=1; i<=n; i++) {
		if (cc[i] == false) {
			visited_stack.clear();
			dfs(G, cc, visited_stack, i);
			ncc += 1;
		}
	}

	cout << k - n + ncc << endl;
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