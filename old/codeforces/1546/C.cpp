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
	vector<bool> left(n, false);
	rep(i,0,n) cin >> A[i];
	vi S(A.begin(), A.end());
	sort(S.begin(), S.end());

	map<int,pi> counts;
	for (int i=0; i<n; i++) {
		if (i%2 == 0) counts[A[i]].first += 1;
		else counts[A[i]].second += 1;
	}

	for (int i=0; i<n; i++) {
		if (i%2 == 0) counts[S[i]].first -= 1;
		else counts[S[i]].second -= 1;
	}

	for (auto p : counts) {
		if (p.second.first != 0 || p.second.second != 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;

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