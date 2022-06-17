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
	int a,b;
	cin >> a >> b;

	if (b < a) {
		rep(i,0,b) cout << "01";
		rep(i,0,a-b) cout << "0";
	}
	else {
		rep(i,0,a) cout << "10";
		rep(i,0,b-a) cout << "1";
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
