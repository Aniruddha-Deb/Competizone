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
	vector<ll> A(n);
	rep(i,0,n) cin >> A[i];

	int q;
	cin >> q;
	rep(j,0,q) {
		int t;
		cin >> t;
		int np = 0;
		ll s = 0;
		int nsat = 0;
		for (int i=n-1; i>=0; i--) {
			s += A[i];
			if (s > (nsat+1)*t) {
				// continue grouping
				nsat++;
			}
			else if (s == (nsat+1)*t) {
				// optimal group
				// cout << "Creating group at " << i << endl;
				np += (nsat+1);
				nsat = 0;
				s = 0;
			}
			else {
				nsat += 1;
			}
		}

		if ((s != 0 && s > nsat*t) ||  ) {
			// cout << "s:" << s << " nsat,t:" << nsat << "," << t << endl; 
			cout << -1 << endl;
		}
		else {
			cout << np + ceil(((double)s)/t) << endl;
		}
	}

}

int main() {
	init();
	int t = 1;
	// cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}
