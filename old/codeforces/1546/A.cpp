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
	vi A(n), B(n);
	int sa, sb;
	sa = sb = 0;
	vi gt,lt;
	rep(i,0,n) {
		cin >> A[i];
		sa += A[i];
	}
	rep(i,0,n) {
		cin >> B[i];
		if (B[i] > A[i]) gt.push_back(i);
		else if (B[i] < A[i]) lt.push_back(i);
		sb += B[i];
	}

	if (sa != sb) {
		cout << -1 << endl;
		return;
	}

	vector<pi> ops;
	while (!gt.empty() && !lt.empty()) {
		int hgt = gt.back();
		int hlt = lt.back();
		ops.push_back({hlt, hgt});
		A[hgt] += 1;
		A[hlt] -= 1;
		if (A[hgt] == B[hgt]) gt.pop_back();
		if (A[hlt] == B[hlt]) lt.pop_back();
	}
	cout << ops.size() << endl;
	for (auto p : ops) {
		cout << p.first+1 << " " << p.second+1 << endl;
	}


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