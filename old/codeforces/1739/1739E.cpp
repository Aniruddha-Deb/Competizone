#include <bits/stdc++.h>
#include <unordered_map>
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

const int LEN = (int)(4*1e5);

unordered_map<bitset<LEN>,int> DP;

int rec(int i, int j, string (&s)[2]) {
    // TODO fix the segfault
    // if (i == 1) {
    //     cout << s[0] << endl;
    //     cout << s[1].substr(0,j) << "\033[91m" << s[1][j] << "\033[0m" << s[1].substr(j+1) << endl;
    // }
    // else {
    //     cout << s[0].substr(0,j) << "\033[91m" << s[0][j] << "\033[0m" << s[0].substr(j+1) << endl;
    //     cout << s[1] << endl;
    // }
    // cout << endl;

    int k;
    bitset<LEN> repr(s[i].substr(j)+s[i^1].substr(j));
    if (DP.find(repr) != DP.end()) {
        return DP[repr];
    }

    // check if the cell currently below us is dirty.
    int ccb = INT_MAX;
    if (s[i^1][j] == '1') {
        // do a DP here as well
        s[i^1][j] = '0';
        ccb = 1+rec(i,j,s);
        s[i^1][j] = '1';
    }

    for (k=j+1; k<s[0].size(); k++) {
        if (s[i][k] == '1' and s[i^1][k-1] == '1') {
            // two dirty squares found at same distance
            s[i][k] = '0';
            s[i^1][k-1] = '0';
            int m1 = rec(i^1,k-1,s);
            int m2 = rec(i,k,s);
            s[i^1][k-1] = '1';
            s[i][k] = '1';
            DP[repr] = min(ccb,1+min(m1,m2));
            return DP[repr];
        }
        else if (s[i][k] == '1') {
            // removal vs cleaning dp transition
            s[i][k] = '0';
            DP[repr] = min(ccb,rec(i,k,s));
            DP[repr] = min(DP[repr],1+rec(i,j,s));
            s[i][k] = '1';
            return DP[repr];
        }
        else if (s[i^1][k-1] == '1') {
            s[i^1][k-1] = '0';
            DP[repr] = min(ccb,rec(i^1,k-1,s));
            DP[repr] = min(DP[repr],1+rec(i,j,s));
            s[i^1][k-1] = '1';
            return DP[repr];
        }
    }
    return 0;   
}

void solve() {

    bitset<LEN> b;
    DP[b] = 0;

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
