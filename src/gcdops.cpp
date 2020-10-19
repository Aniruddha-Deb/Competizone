#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n,b;
		cin >> n;
		bool doable = true;
		for (int i=0; i<n; i++) {
			cin >> b;
			if ((i+1) % b != 0) {
				doable = false;
			}
		}
		if (doable) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
