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
    int n;
    ll x;
    cin >> n >> x;
    vll A;
    ll mi = LLONG_MAX, mx=-1;
    rep(i,0,n) {
        ll t;
        cin >> t;
        if (t >= x) continue;
        mi = min(t, mi);
        mx = max(t, mx);
    }
    ll fact_mx = 1;
    rep(i,mx+1,x+1) {
        fact_mx *= i;
        if (fact_mx > n) {
            cout << "No" << endl;
            return;
        }
    }

    // ignore the ones larger than x.

    vll fact_modx(500005);
    rep(i,0,n) {
        A[i] -= mi;
        cout << A[i] << " ";
    }
    cout << endl;
    fact_modx[0] = 1;
    cout << fact_modx[0] << " ";
    rep(i,1,max(mi+1,mx-mi+1)) {
        fact_modx[i] = (fact_modx[i-1] * (ll)i)%x;
        cout << fact_modx[i] << " ";
    }
    cout << endl;
    ll s = 0;
    rep(i,0,n) {
        cout << "Adding " << A[i] << "! = " << fact_modx[A[i]] << " to ans" << endl;
        s = (s+fact_modx[A[i]])%x;
    }
    cout << (((fact_modx[mi] * s)%x == 0) ? "Yes" : "No") << endl;
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
