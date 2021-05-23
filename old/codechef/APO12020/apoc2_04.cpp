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
		string s;
		cin >> s;

		vector<int> num(s.length());
		for (int i=0; i<s.length(); i++) {
			num[i] = s[i]-48;
		}
		bool flip9 = false;
		ostringstream ans;
		for (int i=0; i<s.length()-1; i++) {
			if (flip9) {
				ans << "9";
			}
			else if (num[i] > num[i+1]) {
				// number is not nice at this point
				flip9 = true;
				ans << num[i]-1;
			}
			else {
				ans << num[i];
			}
		}
		if (flip9) ans << 9;
		else ans << num[s.length()-1];
		cout << ans.str() << endl;

	}
	return 0;
}
