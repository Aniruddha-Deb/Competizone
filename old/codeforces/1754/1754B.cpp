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
    if (n%2 == 0) {
        for (int i=n; i>n/2; i--) {
            cout << i-n/2 << " " << i << " " ;
        }
    }
    else {
        for (int i=(n+1)/2; i>1; i--) {
            cout << i << " " << (n+1)/2 + i - 1 << " ";
        }
        cout << 1;
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
