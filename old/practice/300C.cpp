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

ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    ll res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

ll modInverse(ll a, ll p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}

ll modBinomial(ll n, ll k, ll p) {
// calculates C(n,k) mod p (assuming p is prime).

    ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    ll denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

void solve() {
	int a, b, n;
	cin >> a >> b >> n;

	int d = b-a;
	ll ans = 0;
	rep(i,0,6) {
		rep(j,0,(int)pow(2,i)) {
			int k = 0;
			rep(l,0,i) {
				if ((1<<l)&j) k += pow(10,l)*b;
				else k += pow(10,l)*a;
			}
			if (k > n*b || k < n*a) continue;
			int r = k-n*a;
			if (r%d == 0) {
				// cout << k << endl;
				ans = (ans+modBinomial(n,r/d,MOD))%MOD;
			}
		}
	}
	cout << ans << endl;
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