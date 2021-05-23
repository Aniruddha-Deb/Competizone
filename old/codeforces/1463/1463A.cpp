#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a+b+c) % 9 != 0) cout << "NO" << endl;
		else {
			int k = (a+b+c)/9;
			if (a < k || b < k || c < k) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	return 0;
}
