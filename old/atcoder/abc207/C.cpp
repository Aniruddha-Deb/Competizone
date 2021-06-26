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

	vector<pi> A;
	for (int i=0; i<n; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		int lo = 4, ro = 1;
		if (t == 2 || t == 1) lo = 2;
		if (t == 3 || t == 1) ro = 3;
		A.push_back({lo, l});
		A.push_back({ro, r});
	}

	sort(A.begin(), A.end(), [](auto &L, auto &R) {
		if (L.second != R.second ) return L.second < R.second;
		else return L.first < R.first;
	});

	// for (auto p : A) {
	// 	cout << "(" << p.first << "," << p.second << "), ";
	// }
	// cout << endl;

	ll np = 0;
	ll ctr = 0;
	for (int i=0; i<2*n; i++) {
		if (A[i].first == 1 || A[i].first == 3) {
			// interval closing
			ctr -= 1;
			np += ctr;
		}
		else if (A[i].first == 2 || A[i].first == 4) {
			// interval opening
			ctr++;
		}
	}

	cout << np << endl;
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