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
	int n, k;
	cin >> n >> k;

	// get primes till 1000
	vi P;
	rep(i,2,1001) {
		bool comp = false;
		for (int p : P) {
			if (i%p == 0) {
				comp = true;
				break;
			}
		}
		if (!comp) {
			P.push_back(i);
		}
	}

	int np = P.size();
	vi pf(np,0);
	vi ep;

	// prime factorize every number that comes in
	rep(i,0,n) {
		int c;
		cin >> c;
		rep(j,0,np) {
			int ctr = 0;
			while (c%P[j] == 0) {
				c /= P[j];
				ctr++;
			}
			if (ctr > pf[j]) pf[j] = ctr;
		}
		if (c > 1) {
			// c is prime
			ep.push_back(c);
		}
	}

	// check if k is a factor of pf*ep
	rep(j,0,np) {
		while (pf[j] > 0 && k%P[j] == 0) {
			k /= P[j];
			pf[j]--;
		}
	}
	if (k > 1) {
		// k either has large primes in it or is a large prime itself
		for (int j=0; j<ep.size(); ) {
			if (k%ep[j] == 0) {
				k /= ep[j];
				ep.erase(ep.begin()+j);
			}
			else j++;
		}
		if (k > 1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	else cout << "Yes" << endl;
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