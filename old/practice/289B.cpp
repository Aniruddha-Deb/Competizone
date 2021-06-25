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
	int n, m, d;
	cin >> n >> m >> d;
	int mod = -1;
	map<int,int> freq;
	int M[101][101];
	rep(i,0,n) {
		rep(j,0,m) {
			cin >> M[i][j];
			freq[M[i][j]] += 1;
			if (mod != -1 && M[i][j]%d != MOD) {
				cout << -1 << endl;
				return;
			}
			else if (mod == -1) {
				mod = M[i][j]%d;
			}
		}
	}

	int mfreq = -1;
	for (auto p: freq) {
		if (p.second > mfreq) mfreq = p.second;
	}

	cout << n*m - mfreq << endl;

	// no idea will think more on this


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