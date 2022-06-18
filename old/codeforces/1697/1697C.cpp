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
	string s,t;
	cin >> s >> t;

	string sr = regex_replace(s, regex("b"), "");
	string tr = regex_replace(t, regex("b"), "");
	// cout << sr << " " << tr << endl;

	if (sr.compare(tr) != 0) {
		cout << "NO" << endl;
		return;
	}

	int sp = 0;
	int tp = 0;
	rep(i,0,n) {
		if (s[i] == 'a') sp++;
		if (t[i] == 'a') tp++;
		if (sp < tp) goto NO;
	}

	sp = 0;
	tp = 0;
	for (int i=n-1; i>=0; i--) {
		if (s[i] == 'c') sp++;
		if (t[i] == 'c') tp++;
		if (sp < tp) goto NO;
	}

	cout << "YES" << endl;
	return;

	NO:
		cout << "NO" << endl;
		return;
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
