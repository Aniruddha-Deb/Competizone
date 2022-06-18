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
	int M = -MOD;
	int mx = 0, my = 0;
	rep(i,0,n) {
		rep(j,0,m) {
			cin >> A[i][j];
			if (A[i][j] > M) {
				M = A[i][j];
				my = i;
				mx = j;
			}
		}
	}

	ll My = max(my+1,n-my);
	ll Mx = max(mx+1,m-mx);
	cout << My*Mx << endl;
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
