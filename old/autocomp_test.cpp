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
    cin.tie(nullptr);
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> maxs(k,0);

    ll in;
    for (int i=0; i<n; i++) {
        cin >> in;
        maxs[i%k] = max(maxs[i%k], in);
    }
    ll ans = accumulate(maxs.begin(), maxs.end(), 0LL);
    cout<<ans<<endl;

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
