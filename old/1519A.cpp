#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		ll r, b, d;
		cin >> r >> b >> d;
		ll nrb = r*(d+1);
		ll nbb = b*(d+1);
		if (nrb < b || nbb < r) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
