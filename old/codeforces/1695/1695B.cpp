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
	int n;
	cin >> n;
	vi A(n);
	ll SM = 0;
	ll SJ = 0;
	int midx = 0;
	int m = MOD;
	rep(i,0,n) {
		cin >> A[i];
		if (A[i] < m) {
			m = A[i];
			midx = i;
		}
	}

	if (n%2 == 0) {
		if (midx%2 == 0) cout << "Joe" << endl;
		else cout << "Mike" << endl;
	}
	else {
		cout << "Mike" << endl;
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
