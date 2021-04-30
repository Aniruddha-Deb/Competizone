#include <bits/stdc++.h>
using namespace std;

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
	string s[101];
	while (t-- > 0) {
		int n, a, b;
		cin >> n >> a >> b;
		string eq = "EQUINOX";
		ll sa = 0;
		ll ss = 0;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			if (eq.find(s[0]) == string::npos) sa += b;
			else ss += a;
		}

		if (sa == ss) cout << "DRAW" << endl;
		else if (sa > ss) cout << "ANURADHA" << endl;
		else cout << "SARTHAK" << endl;
		
	}
	return 0;
}
