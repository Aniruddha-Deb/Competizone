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
	vector<vector<int>> G(n+1, vector<int>());
	rep(i,0,n) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// find cycle
	vector<int> cycle;
	vector<int> parent(n+1,-1);
	stack<int> dfs;
	vector<bool> visited(n+1,false);
	int cycle_start = -1, cycle_end = -1;
	dfs.push(1);
	bool cyc_found = false;
	while (!dfs.empty()) {
		int node = dfs.top();
//		cout << node << endl;
		visited[node] = true;
		dfs.pop();
		for (int k : G[node]) {
			if (visited[k] && k != parent[node]) {
				// cycle found
				cycle_start = k;
				cycle_end = node;
				// cout << "Cycle found" << endl;
				cyc_found = true;
				break;
			}
			else if (!visited[k]) {
				parent[k] = node;
				dfs.push(k);
			}
		}
		if (cyc_found) break;
	}
	// cout << cycle_start << " " << cycle_end << endl;

	vector<bool> in_cycle(n+1,false);
	for (int i = cycle_end; i != cycle_start; i=parent[i]) {
		cycle.push_back(i);
		in_cycle[i] = true;
	}
	cycle.push_back(cycle_start);
	in_cycle[cycle_start] = true;

	vector<int> cc_count;

	for (int i : cycle) {
		int num_nodes=0;
		vector<bool> visit(n+1,false);
		stack<int> children;
		children.push(i);
		while (!children.empty()) {
			int node = children.top();
			children.pop();
			visit[node] = true;
			num_nodes++;
			for (int k : G[node]) {
				if (!in_cycle[k] && !visit[k]) {
					children.push(k);
				}
			}
		}
		cc_count.push_back(num_nodes);
	}

	// for (int i : cc_count) {
	// 	cout << i << " ";
	// }
	// cout << endl;



	ll num_paths = 0;
	ll ac_nodes = 0;
	for (int i=0; i<cc_count.size(); i++) {
		ll ni = cc_count[i];
		num_paths += (ni*(ni-1))/2;
		ac_nodes += ni;
		num_paths += 2*ni*(n-ac_nodes);
	}

	cout << num_paths << endl;

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
