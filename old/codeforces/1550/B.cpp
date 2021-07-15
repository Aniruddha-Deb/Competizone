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
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	if (b >= 0) {
		cout << n*(a+b) << endl;
	}
	else {
		// minimum number of deletions
		int ns = 0;
		rep(i,0,n-1) {
			if (s[i] == '0' && s[i+1] == '1') ns++;
		}
		if (s[0] == '1' && s[n-1] == '0') cout << (n*a)+((ns+2)*b) << endl;
		else cout << (n*a)+((ns+1)*b) << endl;
	}
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