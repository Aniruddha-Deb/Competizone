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

bool alice_win(vi A, int k) {
    // A is sorted
    if (k == 0) return true;
    if (2*k-1 > A.size()) return false;
    for (int i=k-1; i<2*k-1; i++) {
        if (A[i] > i-(k-1)+1) {
            return false;
        }
    }
    return true;

//    int ap = A.size()-1;
//    int bp = 0;
//    while (ap >= 0 and A[ap] > k) ap--;
//    // now start the game
//    for (int i=0; i<k; i++) {
//        // check if alice can pick a number off: if she can't, she has lost
//        while (ap >= 0 and A[ap] > k-i) ap--;
//        if (ap < 0) return false;
//        ap--;
//        A[bp++] += k-i;
//    }
//    return true;
}

void solve() {
    int n;
    cin >> n;
    vi A(n);
    rep(i,0,n) cin >> A[i];

    sort(A.begin(), A.end());

    // Binary search on k...
    // TODO figure out why this fails.
    //
    // Bob will add the number to the largest number left over to ensure that 
    // Alice loses fastest. To counter him, Alice will pull out the largest number. 
    // We have 0 <= k <= n
    // Verifying for a particular k:
    // sort the array, and let alice withdraw the largest number and bob add k 
    // to the highest number. 

    int x = 0;
    // let's do linear search to see if this is ok first
//    int i = 0;
//    int max_i = 0;
//    for (; i<=n; i++) {
//        if (alice_win(A, i)) max_i = i;
//        // cout << (alice_win(A, i)?"1":"0") << " ";
//    }
//    cout << max_i << endl;
//    cout << endl;
    for (int i=n; i>0; i/=2) {
        if (alice_win(A, x+i)) {
//            cout << "Alice won at " << x+i << endl;
            x += i;
        }
        else {
//            cout << "Alice lost at " << x+i << endl;
        }
    }
    if (alice_win(A, x+1)) x++;
    cout << x << endl;
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
