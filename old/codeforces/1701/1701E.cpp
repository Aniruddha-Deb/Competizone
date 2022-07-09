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
    int n, m;
    cin >> n >> m;
    string s, t;
    vector<bool> del(n, true);
    cin >> s >> t;
    int tp = 0;
    rep(i,0,n) {
        if (tp < m && s[i] == t[tp]) {
            del[i] = false;
            tp++;
        }
    }

    if (tp != m) {
        cout << -1 << endl;
        return;
    }

    // invariant: all characters marked for deletion before the cursor are 
    // deleted.
    int ops = 0;   // num operations done
    int ndloc = n-1; // next delete location
    int cursor = n; 
    while (cursor > 0 && ndloc >= 0) {
        while (ndloc >= 0 && !del[ndloc]) {
            ndloc--;
        }
        if (ndloc < 0) break;

        // ndloc is before cursor now: compare
        if ((ndloc+2) < cursor-(ndloc+1)) {
            // go home and come back
            ops += ndloc+2;
            cursor = ndloc+1;
        }
        else {
            ops += cursor-(ndloc+1);
        }
        cursor = ndloc+1;

        cursor--;
        ops++;
        ndloc--;
        cout << "deleted " << s[cursor] << endl;
    }

    cout << ops << endl;

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
