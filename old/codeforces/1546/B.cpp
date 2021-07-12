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
	vector<vi> A(m, vi(26,0));
	rep(i,0,n) {
		string s;
		cin >> s;
		rep(j,0,s.length()) {
			A[j][s[j]-'a'] += 1;
		}
	}

	rep(i,0,n-1) {
		string s;
		cin >> s;		
		rep(j,0,s.length()) {
			A[j][s[j]-'a'] -= 1;
		}
	}

	rep(i,0,m) {
		rep(j,0,26) {
			if (A[i][j] == 1) {
				cout << (char)(j+'a');
			}
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