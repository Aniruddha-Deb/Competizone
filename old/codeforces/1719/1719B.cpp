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
    int n, k;
    cin >> n >> k;
    if (k%2 == 1) {
        cout << "YES" << endl;
        for (int i=1; i<n; i+=2) {
            cout << i << " " << i+1 << endl;
        }
    }
    else if (k%2 == 0 && k%4 == 2) {
        cout << "YES" << endl;
        for (int i=1; i<n; i+=2) {
            if ((i+1)%4 == 2) cout << i+1 << " " << i << endl;
            else cout << i << " " << i+1 << endl;
        }
    } 
    else {
        cout << "NO" << endl;
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
