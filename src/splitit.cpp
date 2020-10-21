#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int l;
		cin >> l;
		string s;
		cin >> s;
		char lc = s[l-1];
		bool doable = false;
		for (int i=0; i<l-1; i++) {
			if (s[i] == lc) {
				doable = true;
				break;
			}
		}
		if (doable) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
