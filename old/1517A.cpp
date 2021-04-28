#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		long long n;
		cin >> n;
		if (n%2050 != 0) cout << -1 << endl;
		else {
			n /= 2050;
			int sum = 0;
			while (n>0) {
				int d = n%10;
				sum += d;
				n /= 10;
			}
			cout << sum << endl;
		}
	}
	return 0;
}
