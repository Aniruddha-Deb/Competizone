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

struct Grid {

	vi longitudinal;
};

bool check(vector<string>& A) {
	// check longitudinally for X's
	rep(i,0,10) {
		rep(j,0,6) {
			if (A[i].substr(j,5).compare("XXXXX") == 0) {
				return true;
			}
		}
	}
	// check vertically for X's
	rep(i,0,10) {
		rep(j,0,6) {
			string s = "";
			rep(k,0,5) s += A[j+k][i];
			if (s.compare("XXXXX") == 0) {
				return true;
			}
		}
	}
	// check right diagonally for X's
	rep(i,0,6) {
		rep(j,i,6) {
			string s = "";
			rep(k,0,5) s += A[i+k][j+k];
			if (s.compare("XXXXX") == 0) {
				return true;
			}
		}
	}
	rep(i,1,6) {
		rep(j,0,i) {
			string s = "";
			rep(k,0,5) s += A[i+k][j+k];
			if (s.compare("XXXXX") == 0) {
				return true;				
			}
		}
	}
	// check left diagonally for X's
	rep(i,0,6) {
		rep(j,4,10-i) {
			string s = "";
			rep(k,0,5) s += A[i+k][j-k];
			if (s.compare("XXXXX") == 0) {
				return true;				
			}
		}
	}
	rep(i,1,6) {
		rep(j,10-i,10) {
			string s = "";
			rep(k,0,5) s += A[i+k][j-k];
			if (s.compare("XXXXX") == 0) {
				return true;				
			}
		}
	}
	return false;
}

void solve() {
	vector<string> A(10);
	rep(i,0,10) cin >> A[i];

	rep(i,0,10) {
		rep(j,0,10) {
			if (A[i][j] == '.') {
				A[i][j] = 'X';
				if (check(A)) {
					cout << "YES" << endl;
					return;
				}
				else {
					A[i][j] = '.';
				}
			}
		}
	}
	cout << "NO" << endl;

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