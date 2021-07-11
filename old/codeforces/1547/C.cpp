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
	int k, n, m;
	cin >> k >> n >> m;
	deque<int> A;
	deque<int> B;
	rep(i,0,n) {
		int t;
		cin >> t;
		A.push_back(t);
	}
	rep(i,0,m) {
		int t;
		cin >> t;
		B.push_back(t);
	}

	vi P;
	rep(i,0,n+m) {
		if (!A.empty() && A.front() <= k) {
			if (A.front() == 0) k++;
			P.push_back(A.front());
			A.pop_front();
		}
		else if (!B.empty() && B.front() <= k) {
			if (B.front() == 0) k++;
			P.push_back(B.front());
			B.pop_front();
		}
		else {
			// stalemate!
			break;
		}
	}
	if (P.size() == n+m) {
		for (int i : P) cout << i << " ";
			cout << endl;
	}
	else cout << "-1" << endl;
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