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
		int prev;
		cin >> prev;
		for (int i=1; i<n; i++) {
			cin >> k;
			if ((i-1)%2 == 0) {
				cout << -k << " " << prev << " ";
			}
			prev = k;
		}
		cout << endl;
	}
	return 0;
}
