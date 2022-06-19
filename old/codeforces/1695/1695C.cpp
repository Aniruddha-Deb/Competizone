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

	vector<vi> DP_l(n,vi(m,0));
	vector<vi> DP_u(n,vi(m,0));
	DP_l[0][0] = DP_u[0][0] = A[0][0];
	rep(i,1,n) DP_l[i][0] = DP_u[i][0] = DP_l[i-1][0] + A[i][0];
	rep(i,1,m) DP_l[0][i] = DP_u[0][i] = DP_l[0][i-1] + A[0][i];

	rep(i,1,n) {
		rep(j,1,m) {
			DP_l[i][j] = A[i][j] + min(DP_l[i-1][j],DP_l[i][j-1]);
			DP_u[i][j] = A[i][j] + max(DP_u[i-1][j],DP_u[i][j-1]);
		}
	}

	if (((ll)DP_l[n-1][m-1])*DP_u[n-1][m-1] <= 0) cout << "YES" << endl;
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
