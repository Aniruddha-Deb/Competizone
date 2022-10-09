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

int rec(int i, int j, string (&s)[2]) {
    int k;
    // cout << s[0] << endl;
    // cout << s[1] << endl;
    // cout << "At cell " << i << "," << j << endl;
    for (k=j+1; k<s[0].size(); k++) {
        if (s[i][k] == '1' and s[i^1][k-1] == '1') {
            // two dirty squares found at same distance
            s[i][k] = '0';
            int m1 = rec(i^1,k-1,s);
            s[i][k] = '1';
            s[i^1][k-1] = '0';
            int m2 = rec(i,k,s);
            s[i^1][k-1] = '1';
            return 1+min(m1,m2);
        }
        else if (s[i][k] == '1') {
            return rec(i,k,s);
        }
        else if (s[i^1][k-1] == '1') {
            return rec(i^1,k-1,s);
        }
    }
    return 0;   
}

void solve() {
    int n;
    cin >> n;

    string s[2];
    cin >> s[0] >> s[1];
    int nd = 0;
    for (int i=0; i<n; i++) {
        if (s[0][i] == '1') nd++;
        if (s[1][i] == '1') nd++;
    }

    cout << nd-rec(0,0,s) << endl;
}

int main() {
    init();
    int t = 1;
    // cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
