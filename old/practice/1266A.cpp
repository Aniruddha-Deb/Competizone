#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<char> D(s.begin(), s.end());

	string digits = "02468";
	int sum = 0;
	bool div5 = false;
	bool div4 = false;
	int zeropos = s.find('0');
	if (zeropos != string::npos) div5 = true;
	rep(i,0,n) {
		sum += D[i]-'0';
		if (i != zeropos && digits.find(D[i]) != string::npos && div5) div4 = true;
	}
	if (sum % 3 == 0 && div4) cout << "red" << endl;
	else cout << "cyan" << endl;
}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}