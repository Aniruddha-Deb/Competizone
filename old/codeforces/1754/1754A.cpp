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
    string s;
    cin >> s;
    int qs = 0, as = 0;
    rep(i,0,n) {
        if (s[i] == 'Q') {
            qs++;
        }
        else {
            qs = max(0,qs-1);
        }
    }
    if (qs > 0) cout << "No" << endl;
    else cout << "Yes" << endl;
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
