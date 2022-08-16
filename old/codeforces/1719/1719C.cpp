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
    vi A(n);
    int maxn, imax = 0;
    rep(i,0,n) {
        cin >> A[i];
        if (A[i] >= A[imax]) {
            imax = i;
            maxn = A[i];
        }
    }

    vi LT(n,0);
    for (int i=0; i<n; ) {
        int j = i+1;
        if (i != 0) LT[i]++;
        while (j < n and A[j] < A[i]) {LT[i]++; j++;}
        i = j;
        //cout << i << endl;
    }

    // for (int k=1; k<=n; k++) {
    //     for (int i=1; i<=n; i++) {
    //         if (i-1 == imax) {
    //             // special
    //             if (k <= i-2) cout << 0 << " ";
    //             else cout << k-max(0,i-2) << " ";
    //             continue;
    //         }
    //         if (k <= i-2) cout << 0 << " ";
    //         else if (k <= i-2+LT[i-1]) cout << k - max(0,i-2) << " ";
    //         else cout << LT[i-1] << " ";
    //     }
    //     cout << endl;
    // }

    rep(qp,0,q) {
        int i, k;
        cin >> i >> k;
        if (i-1 == imax) {
            // special
            if (k <= i-2) cout << 0 << endl;
            else cout << k-max(0,i-2) << endl;
            continue;
        }
        if (k <= i-2) cout << 0 << endl;
        else if (k <= i-2+LT[i-1]) cout << k - max(0,i-2) << endl;
        else cout << LT[i-1] << endl;
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
