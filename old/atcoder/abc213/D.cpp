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

void dfs(vector<priority_queue<int,vector<int>, greater<int>>>& G, vector<bool>& visited, vi& parents, int root) {
	if (root == -1) {
		cout << endl;
		exit(0);
	}
	visited[root] = true;
	cout << root << " ";
	if (G[root].empty()) {
		dfs(G, visited, parents, parents[root]);
	}
	else {
		int mnode = G[root].top();
		G[root].pop();
		parents[mnode] = root;
		dfs(G, visited, parents, mnode);
	}
}

void findp(vector<vi>& G_raw, vector<priority_queue<int, vector<int>, greater<int>>>& G, vector<bool>& visited, vi& parents, int root) {
	visited[root] = true;
	for (int i : G_raw[root]) {
		if (!visited[i]) {
			parents[i] = root;
			findp(G_raw, G, visited, parents, i);
			G[root].push(i);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vi> G_raw(n+1, vi());
	vector<priority_queue<int, vector<int>, greater<int>>> G(n+1,priority_queue<int,vector<int>,greater<int>>());
	vector<int> parents(n+1,-1);
	rep(i,0,n-1) {
		int a, b;
		cin >> a >> b;
		G_raw[a].push_back(b);
		G_raw[b].push_back(a);
	}

	vector<bool> visited(n+1,false);
	findp(G_raw, G, visited, parents, 1);
	vector<bool> vis(n+1,false);
	dfs(G,vis,parents,1);

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