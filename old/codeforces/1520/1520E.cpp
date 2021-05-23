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
		int ns = count(s.begin(), s.end(), '*');
		int pms = 0;
		int ctr = -1;
		for (int i=0; i<n; i++) {
			if (s[i] == '*') {
				ctr++;
				if (ctr == ns/2) {
					pms = i;
					break;
				}
			}
		}
		ll ans = 0;
		int pos = pms - ns/2;

		for (int i=0; i<n; i++) {
			if (s[i] == '*') {
				ans += abs(pos-i);
				pos++;
			}
		}

		cout << ans << endl;
	}
	return 0;
}
