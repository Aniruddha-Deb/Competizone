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
	vector<pair<int,int>> D(n);
	unordered_map<int,int> F;
	vector<vector<int>> G(n+1,vector<int>());
	bool dup = false;
	rep(i,0,n) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			dup = true;
		}
		G[a].push_back(b);
		G[b].push_back(a);
		if (F.count(a) > 0) F[a] = F[a]+1;
		else F[a] = 1;
		if (F.count(b) > 0) F[b] = F[b]+1;
		else F[b] = 1;
	}
	if (dup) {
		cout << "NO" << endl;
		return;
	}
	for (auto p : F) {
		if (p.second > 2) {
			cout << "NO" << endl;
			return;
		}
	}

	vector<bool> visited(n+1,false);
	for (int i=1; i<=n; i++) {
		if (visited[i]) continue;
		// DFS cycles
		stack<int> A;
		A.push(i);
		visited[i] = true;
		bool cyc_closed = false;
		int n_traversed = 0;
		while (!A.empty()) {
			int v = A.top();
			A.pop();
			n_traversed++;
			visited[v] = true;
			bool all_vis = true;
			for (int i : G[v]) {
				if (!visited[i]) {
					A.push(i);
					all_vis = false;
				}
			}
			if (all_vis) {
				// cycle closed
				break;
			}
		}

		if (n_traversed%2 != 0) {
			cout << "NO" << endl; // << n_traversed << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
