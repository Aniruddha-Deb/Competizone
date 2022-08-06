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

vector<int> lstsq(100005);
unordered_set<int> sq;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i=0;
    int ctr=0;
    while (true) {
        int k = 1;
        sq.insert(i*i);
        while (ctr < 100005 && k <= 2*i+1) {
            lstsq[ctr++] = i;
            k++;
        }
        if (ctr >= 100005) break;
        i++;
    }

    // for (int i=0; i<20; i++) {
    //     cout << lstsq[i] << " ";
    // }
    // cout << endl;

    // for (int i=0; i<50; i++) {
    //     cout << 2*lstsq[i]-i << " ";
    // }
    // cout << endl;
}

void print_lstsq(int n) {
    if (n == 3) {
        cout << "0 3 2 1 ";
        return;
    }
    if (sq.find(n) != sq.end()) {
        for (int i=n; i>=0; i--) cout << i << " ";
        return;
    }
    int gtsq = (lstsq[n]+1)*(lstsq[n]+1);
    print_lstsq(n-((n-gtsq/2)*2+(1-gtsq%2)));
    for (int i=0; i<((n-gtsq/2)*2+(1-gtsq%2)); i++) {
        cout << n-i << " ";
    }
}

void solve() {
    int n;
    cin >> n;

    print_lstsq(n-1);
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
