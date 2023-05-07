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
    int n, q;
    cin >> n >> q;
    vll A(n);
    rep(i,0,n) cin >> A[i];
    rep(t,0,q) {
        int l, r;
        cin >> l >> r;
        // kadane
        for (int i=l-1; i<r; i++) {
            for (int j=0; j<(r-l+1-i); j++) {
                ll sum = 0;
                ll xr = 0;
                cout << "[" << i << "," << i+j << "] = ";
                for (int k=i; k<=i+j; k++) {
                    sum += A[k];
                    xr ^= A[k];
                }
                cout << sum-xr << " ";
            }
            cout << endl;
        }
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
