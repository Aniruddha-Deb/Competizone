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
    int q;
    cin >> q;
    set<ll> s;
    s.insert(0);
    map<ll,ll> k_mult;
    rep(t,0,q) {
        string op;
        cin >> op;
        ll n;
        cin >> n;
        if (op[0] == '+') {
            s.insert(n);
        }
        else {
            ll i = 1;
            if (k_mult.find(n) != k_mult.end()) {
                i = k_mult[n];
            }
            while (s.find(n*i) != s.end()) {
                i++;
            }
            k_mult[n] = i;
            cout << n*i << endl;
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
