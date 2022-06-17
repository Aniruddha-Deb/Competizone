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

ll DFS(int v, int* ans, vector<vector<int>>& G, vector<pair<ll,ll>>& LR) {
	ll sum = 0;
	for (int u : G[v]) {
		sum += DFS(u,ans,G, LR);
	}

	if (sum < LR[v].first) {
		(*ans)++;
		return LR[v].second;
	}

	return min(LR[v].second, sum);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> G(n+1,vector<int>());
	vector<pair<ll,ll>> LR(n+1);

	rep(i,2,n+1) {
		int k;
		cin >> k;
		G[k].push_back(i);
	}
	rep(i,1,n+1) {
		cin >> LR[i].first >> LR[i].second;
	}

	int ans = 0;
	DFS(1,&ans,G,LR);

	cout << ans << endl;
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
