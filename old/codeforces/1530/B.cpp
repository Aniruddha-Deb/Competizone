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
	int h, w;
	cin >> h >> w;
	if (h%2 != 0 && w%2 != 0) {
		rep(i,0,h) {
			rep(j,0,w) {
				if (i == 0 || i == h-1) cout << (j+1)%2;
				else if (j == 0 || j == w-1) cout << (i+1)%2;
				else cout << 0;
			}
			cout << endl;
		}
	}
	else if (h%2 != 0 && w%2 == 0) {
		rep(i,0,h) {
			rep(j,0,w) {
				if (i == 0 || i == h-1) cout << j%2;
				else if (j == 0 || j == w-1) cout << (i+1)%2;
				else cout << 0;
			}
			cout << endl;
		}
	}
	else if (h%2 == 0 && w%2 != 0) {
		rep(i,0,h) {
			rep(j,0,w) {
				if (i == 0) cout << (j+1)%2;
				else if (j == 0 || j == w-1) cout << (i+1)%2;
				else if (i == h-1 && (j!=0 && j != w-1)) cout << (j+1)%2;
				else cout << 0;
			}
			cout << endl;
		}
	}
	else if (h%2 == 0 && w%2 == 0) {
		rep(i,0,h) {
			rep(j,0,w) {
				if (i == 0) cout << j%2;
				else if (j == 0 || j == w-1) cout << (i+1)%2;
				else if (i == h-1 && (j!=0 && j < w-2)) cout << (j+1)%2;
				else cout << 0;
			}
			cout << endl;
		}
	}
	cout << endl;
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