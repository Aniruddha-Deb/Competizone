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
    int x_max = 0;
    int x_min = 0;
    int y_max = 0;
    int y_min = 0;
    rep(i,0,n) {
        int x,y;
        cin >> x >> y;
        x_max = max(x_max,x);
        x_min = min(x_min,x);
        y_min = min(y_min,y);
        y_max = max(y_max,y);
    }
    cout << (x_max*2) + ((-x_min)*2) + y_max*2 + ((-y_min)*2) << endl;
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
