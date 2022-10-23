#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 998244353L
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

vector<ll> lp(3*1e5+5);

inline ll pmod(ll i, ll n) { return (i%n + n) % n; }

void sieve() {
    int n = 3*1e5 + 5;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    ll cp = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
            if (cp < (ll)(1e12+10)) cp *= i;
        }
        lp[i] = cp;
    }
}

void solve() {

    sieve();

    ll n, m;
    cin >> n >> m;
    ll m2 = m%MOD2;
    ll ans = 0;
    ll ans_sub = m2;
    ll p_m = m2;
    for (int i=2; i<=n; i++) {
        p_m = (p_m * (m2)) % MOD2;
        // cout << "lp["<<i<<"] = " << lp[i] << endl;
        ans_sub = (ans_sub * ((m/lp[i])%MOD2)) % MOD2;
        ans = (ans + pmod(p_m - ans_sub, MOD2)) % MOD2;
    }

    cout << ans << endl;
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
