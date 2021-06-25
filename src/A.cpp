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

	if (n%2 == 0) {
		for (int i=1; i<=n/2; i++) {
			cout << 2*i << " " << 2*i-1 << " ";
		}
		cout << endl;
	}
	else {
		for (int i=1; i<=(n-3)/2; i++) {
			cout << 2*i << " " << 2*i-1 << " ";			
		}
		cout << n << " " << n-2 << " " << n-1 << " " << endl;
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