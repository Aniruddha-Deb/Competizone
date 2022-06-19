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
	ll n_ops = 0;
	ll rdecr = 0;
	rep(i,0,n) {
		cin >> A[i];
		A[i] = A[i] - rdecr;
		if (i >= 1) {
			int delta = A[i] - A[i-1];
			if (delta > 0) {
				A[i] = A[i-1];
				rdecr += delta;
			}
			else {
				A[i-1] = A[i];
			}
			n_ops += abs(delta);
		}
		// cout << n_ops << " ";
	}
	// cout << endl;

	cout << abs(A[n-1]) + n_ops << endl;
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
