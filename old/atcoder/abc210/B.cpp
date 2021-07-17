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
	string s;
	cin >> s;
	rep(i,0,n) {
		if (i%2 == 0 && s[i] == '1') {
			cout << "Takahashi" << endl;
			return;
		}
		else if (i%2 != 0 && s[i] == '1') {
			cout << "Aoki" << endl;
			return;
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