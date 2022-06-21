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

pi calc_m(int n, vector<vi>& G, vector<bool>& visited) {
	visited[n] = true;
	vector<pi> infcts;
	for (int c : G[n]) {
		if (!visited[c]) {
			pi infct = calc_m(c, G, visited);
			infcts.push_back(infct);
		}
	}
	if (infcts.size() == 0) return {1,0};
	else if (infcts.size() == 1) return {1,1};
	else {
		int idx = (infcts[0] < infcts[1]) ? 0 : 1;
		return {1+infcts[idx].first,1+infcts[idx].second};
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vi> G(n+1,vi());

	// cout << "Allocated G" << endl;

	rep(i,0,n-1) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<bool> visited(n+1,false);
	pi m = calc_m(1,G,visited);
	cout << n-(m.first+m.second) << endl;
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
