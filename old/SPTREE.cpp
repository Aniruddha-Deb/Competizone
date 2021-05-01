#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int d_rec(int n1, int n2, map<int, vector<int>>& tree, int depth, set<int>& visited) {
	vi nodes = tree[n1];
	visited.insert(n1);
	for (int i : nodes) {
		if (visited.find(i) != visited.end()) continue;
		if (i == n2) return depth+1;
		else {
			int d = d_rec(i, n2, tree, depth+1, visited);
			if (d != -1) return d;
		}
	}
	return -1;
}

int d(int n1, int n2, map<int, vector<int>>& tree) {
	if (n1 == n2) return 0;
	set<int> vnodes = set<int>();
	return d_rec(n1, n2, tree, 0, vnodes);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k, a;
		cin >> n >> k >> a;
		vector<int> special(k);
		map<int, vector<int>> tree;

		for (int i=1; i<=n; i++) {
			tree[i] = vector<int>();
		}

		for (int i=0; i<k; i++) {
			cin >> special[i];
		}

		for (int i=0; i<n-1; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			tree[n1].push_back(n2);
			tree[n2].push_back(n1);
		}

		vi max_diffs;
		vi max_diff_nodes;
		map<int, vector<int>> dspn;
		for (int i=1; i<=n; i++) {
			dspn[i] = vector<int>();
		}
		for (int i=1; i<=n; i++) {
			for (int j=0; j<=k; j++) {
				dspn[i].push_back(d(i,special[j],tree));
			}
		}

		for (int i=1; i<=n; i++) {
			int max_diff = dspn[a][0] - dspn[i][0];
			int max_diff_node = special[0];
			//cout << "Initial max_diff = " << max_diff << endl;
			for (int j=1; j<k; j++) {
				int diff = dspn[a][j] - dspn[i][j];
			//	cout << "\td("<<a<<", "<<special[i]<<") = " << d(a, special[i], tree) << endl;
			//	cout << "\td("<<i<<", "<<special[i]<<") = " << d(i, special[i], tree) << endl;
			//	cout << "\tcalc max_diff = " << diff << " for special node " << special[i] << endl;
				if (diff > max_diff) {
					max_diff = diff;
					max_diff_node = special[j];
				}
			}
			max_diffs.push_back(max_diff);
			max_diff_nodes.push_back(max_diff_node);
		}

		for (int i : max_diffs) {
			cout << i << " ";
		}
		cout << endl;
		for (int i : max_diff_nodes) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
