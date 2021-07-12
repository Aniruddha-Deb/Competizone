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

	const int INF = INT_MAX - (int)1e6;
	int n, k;
	cin >> n >> k;
	vi A(k), T(n,INF);
	rep(i,0,k) cin >> A[i];
	rep(i,0,k) cin >> T[A[i]-1];

	vi L(n,INF), R(n,INF);
	int p = INF;
	rep(i,0,n) {
		p = min(p+1,T[i]);
		L[i] = p;
	}
	p = INF;
	for (int i=n-1; i>=0; i--) {
		p = min(p+1,T[i]);
		R[i] = p;
	}

	rep(i,0,n) {
		cout << min(L[i], R[i]) << " ";
	}
	cout << endl;
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