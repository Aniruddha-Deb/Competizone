#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

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

		int n1 = count(s.begin(), s.end(), '1');
		if (n == 1 && s[0] == '0') cout << "BOB" << endl;
		else if (n%2 == 1 && s[n/2] == '0') {
			if (n1 == n-1) cout << "BOB" << endl;
			else cout << "ALICE" << endl;
		}
		else cout << "BOB" << endl;
	}
	return 0;
}
