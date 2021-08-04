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
	int m;
	cin >> m;
	vector<pi> v(m);
	int tsum = 0;
	int bsum = 0;
	rep(i,0,m) {
		cin >> v[i].first;
		tsum += v[i].first;
	}
	rep(i,0,m) {
		cin >> v[i].second;
		bsum += v[i].second;
	}

	vector<pi> s(m);
	s[0].first = v[0].first;
	s[m-1].second = v[m-1].second;
	rep(i,1,m) {
		s[i].first = s[i-1].first + v[i].first;
	}
	for (int i=m-2; i>=0; i--) {
		s[i].second = s[i+1].second + v[i].second;
	}

	int msum = INT_MAX;
	for (int i=0; i<m; i++) {
		int bs = max(s[m-1].first-s[i].first, s[0].second-s[i].second);
		if (bs < msum) {
			msum = bs;
		}
	}

	cout << msum << endl;
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