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
	int n, m;
	cin >> n >> m;
	vector<vi> A(n,vi(m));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> A[i][j];
		}
	}

	ll lrow = (A[0][0]-1)/7;
	ll lcol = A[0][0]%7 != 0 ? A[0][0]%7 : 7;
	//cout << lrow << " " << lcol << endl;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int pos = (lcol+j)%7 != 0 ? (lcol+j)%7 : 7;
			//cout << (lrow+i) * 7 << " " << pos << endl;
			if (A[i][j] != (lrow+i)*7 + pos) {
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
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
