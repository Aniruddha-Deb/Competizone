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
    cin >> n;
    vi A(n);
    bool mon_incr = true;
    bool mon_decr = true;
    bool single_peak = true;
    bool peak_turn = false;
    rep(i,0,n) {
        cin >> A[i];
    }
    rep(i,1,n) {
        if (A[i] < A[i-1]) {
            mon_incr = false;
            peak_turn = true;
            //cout << "not mon incr" << endl;
        }
        if (A[i] > A[i-1]) {
            mon_decr = false;
            if (peak_turn) {
                single_peak = false;
            }
            //cout << "not mon decr" << endl;
        }

    }

    if (!mon_incr and !mon_decr and !single_peak) cout << "NO" << endl;
    else cout << "YES" << endl;

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
