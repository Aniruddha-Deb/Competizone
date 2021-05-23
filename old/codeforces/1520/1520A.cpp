#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

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
	while (t-- > 0) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool sus = false;
		set<char> chars;
		char prevchar = s[0];
		chars.insert(prevchar);
		for (int i=1; i<n; i++) {
			if (s[i] != prevchar && chars.find(s[i]) != chars.end()) {
				sus = true;
				break;
			}
			chars.insert(s[i]);
			prevchar = s[i];
		}

		if (!sus) cout << "YES" << endl;
		else cout << "NO" << endl;
			
	}
	return 0;
}
