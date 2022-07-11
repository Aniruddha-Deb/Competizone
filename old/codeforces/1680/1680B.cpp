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
	int n, m;
	cin >> n >> m;
	vector<vector<char>> G(n,vector<char>(m,0));
	int min_xd = INT_MAX;
	int min_yd = INT_MAX;
	int min_d = INT_MAX;
	int min_dx = 0;
	int min_dy = 0;
	rep(i,0,n) {
		rep(j,0,m) {
			cin >> G[i][j];
			if (G[i][j] == 'R') {
				if (i+j < min_d) {
					min_d = i+j;
					min_dx = j;
					min_dy = i;
				}
				if (i < min_yd) min_yd = i;
				if (j < min_xd) min_xd = j;
			}
		}
	}

	if (min_yd < min_dy || min_xd < min_dx) cout << "NO" << endl;
	else cout << "YES" << endl;

	/*
	EEREE
	EREEE
	REEEE
	*/
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
