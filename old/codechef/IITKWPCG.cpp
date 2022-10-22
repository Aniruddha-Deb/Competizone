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
    vector<vector<int>> G(n, vector<int>());
    unordered_map<pair<int,int>,int> cost;
    for (int i=0; i<m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        G[a].push_back(b);
        G[b].push_back(a);
        int logc = log2l(c);
        cost[{a,b}] = cost[{b,a}] = c;
    }

    // now do a MST
    priority_qu


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
