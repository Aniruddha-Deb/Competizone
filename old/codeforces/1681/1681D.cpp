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
	ll x;
	cin >> n >> x;
	queue<ll> Q;
	map<ll,int> D;
	Q.push(x);
	D[x] = 0;
	while (!Q.empty() && (int)(to_string(Q.front()).size()) < n) {
		ll k = Q.front();
		int depth = D[k];
		//cout << k << "," << depth << endl;
		Q.pop();
		vector<bool> done(10,false);
		ll ko = k;
		while (k != 0) {
			int d = k%10;
			if (d != 0 && d != 1 && !done[d]) {
				ll kn = ko*d;
				if (!D.count(kn)) { // wow, ok
					D[kn] = D[ko]+1;
					Q.push(kn);
				}
				done[d] = true;
			}
			k /= 10;
		}
	}
	if (Q.empty()) cout << -1 << endl;
	else cout << D[Q.front()] << endl; // " " << Q.front().second << endl;
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
