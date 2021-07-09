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
	vi A(n), B(m);
	rep(i,0,n) cin >> A[i];
	rep(i,0,m) cin >> B[i];

	int ans = 0;
	rep(t,0,512) {
		bool allexists = true;
		rep(i,0,n) {
			bool exists = false;
			rep(j,0,m) {
				if (((A[i]&B[j])|t) == t) {
					exists = true;
					break;
				}
			}
			if (!exists) {
				allexists = false;
				break;
			}
		}
		if (allexists) {
			cout << t << endl;
			break;
		}
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