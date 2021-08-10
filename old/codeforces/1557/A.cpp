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
	int n;
	cin >> n;
	vi A(n);
	ll sum, max;
	cin >> max;
	sum = max;
	rep(i,1,n) {
		int t;
		cin >> t;
		if (t > max) max = t;
		sum += t;
	}

	cout << ((double)sum-max)/(n-1) + max << endl;
}

int main() {
	init();
	int t = 1;
	cout << setprecision(10);
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}