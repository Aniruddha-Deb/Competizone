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
	vi A(n-1);
	int temp;
	cin >> temp;
	rep(i,0,n-1) cin >> A[i];
	if (n == 1 || n == 2) {
		cout << 0 << endl;
		return;
	}
	sort(A.begin(), A.end());
	ll ans = 0;
	while (A.size() > 1 && A.back() > A.front()) {
		ans += A.back();
		// cout << A.back() << " ";
		A.pop_back();
		A.erase(A.begin());
	}
	// cout << endl;
	cout << -ans << endl;
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