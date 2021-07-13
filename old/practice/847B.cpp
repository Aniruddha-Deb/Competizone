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

struct comp {
	bool operator() (vi& left, vi& right) {
		return left.back() < right.back();
	}
	bool operator() (int left, vi& right) {
		return left < right.back();
	}
	bool operator() (vi& left, int right) {
		return left.back() < right;
	}
};

void solve() {
	int n;
	cin >> n;

	vi A(n);
	rep(i,0,n) cin >> A[i];
	vector<vi> S;
	for (int u : A) {
		bool push_back = false;
		// binary search position
		int l=0,h=S.size();
		while (h > l) {
			int m = (l+h)/2;
			if (S[m].back() < u) h = m;
			else l = m+1;
		}
		if (h == S.size()) {
			vi nq;
			nq.push_back(u);
			S.push_back(nq);
		}
		else {
			S[h].push_back(u);
		}
	}

	for (vi& v : S) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
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