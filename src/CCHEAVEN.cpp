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
	while (t-- > 0) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int w = 0;
		int b = 0;
		bool gth = false;
		for (int i=0; i<n; i++) {
			if (s[i] == '1') w++;
			else b++;

			if (w >= b) {
				gth = true;
				break;
			}
		}
		if (w >= b || gth) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
