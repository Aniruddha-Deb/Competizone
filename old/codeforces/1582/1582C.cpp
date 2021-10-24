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

int palindromize(string& s, int i, char ch) {
	//cout << s << endl;
	while (s[i] == s[s.length()-1-i] && i < s.length()) i++;
	if (i == s.length()) return 0;
	if (s[i] == ch) return 1 + palindromize(s.erase(i,1),i,ch);
	else if (s[s.length()-1-i] == ch) return 1 + palindromize(s.erase(s.length()-1-i,1),i,ch);
	else return INT_MIN;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int fc = 0;
	int lc = s.length()-1;

	while (s[fc] == s[lc] && fc < s.length() && lc >= 0) {
		fc++;
		lc--;
	}

	if (s[fc] == s[lc]) cout << 0 << endl;
	else {
		string strfcd = s;
		string strlcd = s;		
		int fcd = palindromize(strfcd,fc,s[fc]);
		//cout << " " << endl;
		int lcd = palindromize(strlcd,fc,s[lc]);
		//cout << fcd << " " << lcd << endl;
		if (fcd < 0 && lcd < 0) cout << -1 << endl;
		else if (fcd < 0 && lcd >= 0) cout << lcd << endl;
		else if (fcd >= 0 && lcd < 0) cout << fcd << endl;
		else cout << min(fcd,lcd) << endl;
	}
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
