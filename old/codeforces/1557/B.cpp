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
	vector<pi> A;
	rep(i,0,n) {
		int t;
		cin >> t;
		A.push_back({i,t});
	}

	sort(A.begin(), A.end(), [](auto& l, auto& r) {
		return l.second < r.second;
	});

	int ns = 0;
	rep(i,1,n) {
		if (A[i].first != A[i-1].first + 1) ns++;
	}

//	cout << ns << " ";
	if (ns+1 <= k) cout << "YES" << endl;
	else cout << "NO" << endl;
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