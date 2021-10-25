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
	string s;
	cin >> s;
	char minchar = 'z';
	for (char c : s) {
		if (c < minchar) minchar = c;
	}
	cout << minchar << " ";
	bool pmc = false;
	for (char c : s) {
		if (c == minchar && !pmc) {pmc = true;}
		else {cout << c;}
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
