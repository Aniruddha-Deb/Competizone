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

int DP[1005][2005];
int FS[1005][2005];

void solve() {
	int n;
	cin >> n;
	vector<int> A(n+1);
	int maxn = 0;
	rep(i,1,n+1) {
		cin >> A[i];
		DP[0][i] = A[i];
		FS[0][A[i]]++;
		if (A[i] > maxn) maxn = A[i];
	}

	for (int i=1; i<=1003; i++) {
		for (int j=1; j<=n; j++) {
			DP[i][j] = FS[i-1][DP[i-1][j]];
			FS[i][DP[i][j]]++;
		}
	}

	int q;
	cin >> q;
	rep(_q,0,q) {
		int x,k;
		cin >> x >> k;
		if (k > 1003) cout << DP[1003][x] << endl;
		else cout << DP[k][x] << endl;
	}

	memset(FS,0,sizeof(FS));
	memset(DP,0,sizeof(DP));
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
