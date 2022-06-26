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
	vi A(n);
	vi W1, W2;
	rep(i,0,n) cin >> A[i];
	rep(i,0,n) {
		int t;
		cin >> t;
		if (t == 1) W1.push_back(A[i]);
		else W2.push_back(A[i]);
	}

	sort(W1.rbegin(), W1.rend());
	sort(W2.rbegin(), W2.rend());

	int l = 0;
	int r = W2.size();
	ll sum2 = accumulate(W2.begin(),W2.end(), 0ll);
	ll sum1 = 0;
	int ans = INT_MAX;
	for (; l<=W1.size(); l++) {
		while (r > 0 && sum1 + sum2 - W2[r-1] >= m) {
			r--;
			sum2 -= W2[r];
		}
		if (sum2 + sum1 >= m) {
			ans = min(ans, 2*r+l);
		}
		if (l != W1.size()) {
			sum1 += W1[l];
		}
	}

	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
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
