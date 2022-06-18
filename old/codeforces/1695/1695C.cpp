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
	int n, m;
	cin >> n >> m;
	vector<vi> A(n,vi(m));
	rep(i,0,n) {
		rep(j,0,m) {
			cin >> A[i][j];
		}
	}

	if ((n+m-1)%2 != 0) {
		// odd length path will never be zero
		cout << "NO" << endl;
		return;
	}

	vector<vi> DP(n,vi(m,0));
	DP[0][0] = A[0][0];
	rep(i,1,n) DP[i][0] = DP[i-1][0] + A[i][0];
	rep(i,1,m) DP[0][i] = DP[0][i-1] + A[0][i];

	rep(i,1,n) {
		rep(j,1,m) {
			int o1 = DP[i-1][j] + A[i][j];
			int o2 = DP[i][j-1] + A[i][j];
			if (o2 >= 0 && o1 >= 0) {
				DP[i][j] = min(o1,o2);
			}
			else if (((ll)o2)*o1 < 0) {
				if (abs(o2) > abs(o1)) DP[i][j] = o1;
				else DP[i][j] = o2;
			}
			else {
				DP[i][j] = max(o1,o2);
			}
		}
	}

	if (DP[n-1][m-1] == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
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
