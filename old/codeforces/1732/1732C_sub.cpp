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

        // start from end
        ll sum = 0;
        ll xr = 0;
        ll ms, mi, mj;
        ms = mi = mj = 0;
        mi = l;
        mj = r;
        for (int i=l-1; i<r; i++) {
            sum += A[i];
            xr ^= A[i]; 
        }
        ll mv = sum - xr;
        ll tsum = sum;
        ll txr = xr;
        int j = r-1;
        int i = l-1;
        for (; j>i; j--) {
            tsum -= A[j];
            txr ^= A[j];
            if (tsum-txr < mv) {
                // cout << i << "," << j << " = " << tsum-txr << ", break" << endl;
                tsum += A[j];
                txr ^= A[j];
                break;
            }
            else {
                // cout << i << "," << j << " = " << mv << endl;
            }
        }
        for (; i<j; i++) {
            tsum -= A[i];
            txr ^= A[i];
            if (tsum-txr < mv) {
                // cout << i << "," << j << " = " << tsum-txr << ", break" << endl;
                break;
            }
            else {
                // cout << i << "," << j << " = " << mv << endl;
            }
        }

        cout << i+1 << " " << j+1 << endl;
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
