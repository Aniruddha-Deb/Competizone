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

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	rep(i,0,n) cin >> A[i];
	vector<int> bc(32);
	rep(i,0,31) {
		rep(j,0,n) {
			if (A[j] & (1 << i)) bc[i]++;
		}
	}

	// bc = 0 for all => everything possible
	int ctr = 0;
	while (bc[ctr] == 0 && ctr < 31) ctr++;
	if (ctr == 31) {
		// all bits are 0
		rep(i,0,n) {
			cout << i+1 << " ";
		}
		cout << endl;
		return;
	}
	int d = bc[ctr];
	rep(i,ctr+1,31) {
		d = gcd(d,bc[i]);
	}

	// print all factors of d; can be done naively
	rep(i,1,d+1) {
		if (d%i == 0) cout << i << " ";
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
