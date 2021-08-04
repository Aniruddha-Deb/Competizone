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
	string s;
	cin >> s;

	// make prefix sums for abcabcab.. bcabcabc... cabcabca...
	vector<vi> sums(6,vi(n));
	sums[0][0] = s[0] == 'a' ? 0 : 1;
	sums[1][0] = s[0] == 'b' ? 0 : 1;
	sums[2][0] = s[0] == 'c' ? 0 : 1;
	sums[3][0] = s[0] == 'a' ? 0 : 1;
	sums[4][0] = s[0] == 'c' ? 0 : 1;
	sums[5][0] = s[0] == 'b' ? 0 : 1;
	int ctr = 0;
	string s1 = "abc";
	string s2 = "acb";
	rep(i,1,n) {
		rep(j,0,3) {
			sums[j][i] = sums[j][i-1];
			sums[j][i] += (s[i] == s1[(j+(i%3))%3] ? 0 : 1);
		}
		rep(j,0,3) {
			sums[j+3][i] = sums[j+3][i-1];
			sums[j+3][i] += (s[i] == s2[(j+(i%3))%3] ? 0 : 1);
		}
	}

	rep(i,0,6) {
		sums[i].insert(sums[i].begin(),0);
	}

	while (m-- > 0) {
		int l, r;
		cin >> l >> r;
		l -= 1;
		int min = sums[0][r] - sums[0][l];
		rep(j,1,6) {
			int k = sums[j][r] - sums[j][l];
			if (k < min) min = k;
		}
		cout << min << endl;
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