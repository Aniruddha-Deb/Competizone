#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n;
		int min = INT_MAX;
		for (int i=0; i<n; i++) {
			cin >> k;
			if (k < min) min = k;
		}
		if (n%min == 0) cout << n/min << endl;
		else cout << n/min + 1 << endl;
	}
	return 0;
}
