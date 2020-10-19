#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, x, p, k, t;
		cin >> n >> x >> p >> k;
		vector<int> N;
		for (int i=0; i<n; i++) {
			cin >> t;
			N.push_back(t);
		}
		sort(N,n);
		if (N[p-1] == x) cout << 0 << endl;
		else if (
	}
	return 0;
}
