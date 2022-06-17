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
	vector<int> A(n);
	rep(i,0,n) {
		cin >> A[i];
	}

	vector<ll> B(n);
	rep(i,0,n) {
		if (i == 0) B[i] = A[i];
		else B[i] = A[i] + B[i-1];
	}

	if (B[n-1] != 0) {
		cout << "NO" << endl;
		return;
	}

	bool p = true;
	rep(i,0,n) {
		if (B[i] < 0) {
			p = false;
			break;
		}
		else if (B[i] == 0) {
			i++;
			while (i < n) {
				if (B[i] != 0) {
					p = false;
					break;
				}
				i++;
			}
		}
	}

	if (p) cout << "YES" << endl;
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
