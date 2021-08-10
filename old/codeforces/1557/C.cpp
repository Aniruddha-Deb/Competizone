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

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
	ll n, k;
	cin >> n >> k;

	if (k == 0) cout << 1 << endl;
	else if (n == 1) cout << binpow(2,k,MOD) << endl;
	else if (n%2 == 0) cout << (binpow(2,k*(n-1),MOD))%MOD << endl;
	else {
		// n is odd
		cout << (binpow(binpow(2,n-1,MOD)+1,k,MOD))%MOD << endl;
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