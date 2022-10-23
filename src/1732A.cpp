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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void solve() {
    int n;
    cin >> n;
    vi A(n);
    int g = 0;
    rep(i,0,n) {
        cin >> A[i];
        g = gcd(A[i], g);
    }
    if (g == 1) {
        cout << 0 << endl;
        return;
    }
    if (gcd(g,gcd(A[n-1],n)) == 1 or n == 1) {
        cout << 1 << endl;
    }
    else if (gcd(g,gcd(A[n-2],n-1)) == 1) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
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
