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
	int n, k;
	cin >> n >> k;
	vi A(n);
	rep(i,0,n) cin >> A[i];

	if (k == 1) {
		if (n%2 == 0) cout << n/2 - 1 << endl;
		else cout << n/2 << endl;
	}
	else {
		int ctr = 0;
		rep(i,1,n-1) {
			if (A[i] > A[i-1] + A[i+1]) ctr++;
		}
		cout << ctr << endl;
	}
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
