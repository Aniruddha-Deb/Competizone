#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vi C(n);
	rep(i,0,n) cin >> C[i];
	vi N(n);
	map<int,int> freq;
	int nd = 0;
	rep(i,0,k) {
		if (freq[C[i]] == 0) {
			nd += 1;
		}
		freq[C[i]] += 1;
	}
	int mnd = nd;
	rep(i,k,n) {
		freq[C[i-k]] -= 1;
		if (freq[C[i-k]] == 0) {
			nd -= 1;
		}
		if (freq[C[i]] == 0) {
			nd += 1;
		}
		freq[C[i]] += 1;
		if (nd > mnd) mnd = nd;
	}
	cout << mnd << endl;
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}