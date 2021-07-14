#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
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
	vi A(n+1);
	rep(i,1,n+1) {
		for(int j=2*i; j <= n; j+=i) {
			A[j]++;
		}
	}
	A[0] = 1;
	int S = 1;
	rep(i,1,n+1) {
		A[i] = (A[i]+S)%MOD;
		S = (S+A[i])%MOD;
	}
	cout << A[n] << endl;
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}