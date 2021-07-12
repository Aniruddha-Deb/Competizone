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

	for (int i=0; i<n; i++) {
		
	}

	for (int i=0; i<n-1; i++) {
		if (A[i] == A[i+1] && left[i] && left[i+1]) {
			left[i] = false;
			left[i+1] = false;
			i++;
		}
	}

	bool allright = true;
	for (bool b : left) {
		if (b) {
			allright = false;
			break;
		}
	}

	if (allright) cout << "YES" << endl;
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