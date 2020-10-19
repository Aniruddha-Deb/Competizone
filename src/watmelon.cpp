#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n;
		int sum = 0;
		for (int i=0; i<n; i++) {
			cin >> k;
			sum += k;
		}
		if (sum < 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
