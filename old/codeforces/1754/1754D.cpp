#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD2 1000000087
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

int mypow(ll a,ll b,ll mod){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a%mod;
    }
    ll val = mypow(a,b/2,mod);
    val = (val*val)%mod;
    if(b&1){
        return (val*a)%mod;
    }
    else{
        return val%mod;
    }
}

void solve() {
    ll n;
    ll x;
    cin >> n >> x;
    vll A(n);
    rep(i,0,n) {
        cin >> A[i];
    }
    vll fact1(x+10);
    vll fact2(x+10);
    fact1[0] = 1;
    fact2[0] = 1;
    rep(i,1,x+2) {
        fact1[i] = (fact1[i-1]*i)%MOD;
        fact2[i] = (fact2[i-1]*i)%MOD2;
    }
    
    ll sum1 = 0;
    ll sum2 = 0;
    rep(i,0,n) {
        sum1 = (sum1+fact1[A[i]])%MOD;
        sum2 = (sum2+fact2[A[i]])%MOD2;
    }

    ll val1 = (sum1*mypow(fact1[x],MOD-2,MOD))%MOD;
    ll val2 = (sum2*mypow(fact2[x],MOD2-2,MOD2))%MOD2;

    if (val2 <= n) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
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
