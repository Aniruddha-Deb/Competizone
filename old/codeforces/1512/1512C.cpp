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
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		int n0 = count(s.begin(), s.end(), '0');
		int n1 = count(s.begin(), s.end(), '1');
		int na = a - n0;
		int nb = b - n1;
		int n = a+b;
		if (a%2 == 1 && b%2 == 1) cout << -1 << endl;
		else if (na < 0 || nb < 0) cout << -1 << endl;
		else {
			bool palin = true;
			for (int i=0; i<(n+1)/2; i++) {
				if (s[i] != s[n-1-i]) {
					if (s[i] == '?' || s[n-1-i] == '?') {
						if (s[i] != '?') s[n-1-i] = s[i];
						else s[i] = s[n-1-i];

						if (s[i] == '1') nb--;
						else na--;
					}
					else {
						palin = false;
						break;
					}
				}
			}

			for (int i=0; i<(n+1)/2; i++) {
				if (s[i] == '?' && s[n-1-i] == '?') {
					int sub = 2;
					if (i == n-1-i) sub = 1;
					if (na >= nb) { na -= sub; s[i] = s[n-1-i] = '0';}
					else { nb -= sub; s[i] = s[n-1-i] = '1';}
				}
			}

			if (!palin || na != 0 || nb != 0) {
				cout << -1 << endl;
			}
			else cout << s << endl;
		}
	}
	return 0;
}
