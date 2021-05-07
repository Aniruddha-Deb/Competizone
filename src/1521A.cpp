#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

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
		ll a, b;
		cin >> a >> b;
		if (b == 1) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			cout << a*(b-1) << " " << a*(b+1) << " " << a*2*b << endl;
		}
	}
	return 0;
}
