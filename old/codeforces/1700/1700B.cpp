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

char s[100005];
char ans[100005];
void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	vector<char> s(str.begin(), str.end());
	vector<char> ans(n);

	rep(i,0,n) {
		s[i] = s[i]-'0';
	}

	if (s[0] >= 8) {
		// target 1222..21
		ans[n-1] = (11-s[n-1])%10;
		int carry = (s[n-1]+ans[n-1])/10;
		for (int i=n-2; i>0; i--) {
			ans[i] = (12-s[i]-carry)%10;
			carry = (s[i]+ans[i])/10;
		}
		if (n > 1) ans[0] = (12-s[0]-carry);
	}
	else {
		// target 999...9
		rep(i,0,n) {
			ans[i] = (9-s[i]);
		}
	}

	rep(i,0,n) ans[i] = ans[i] + '0';
	string apr(ans.begin(), ans.end());
	cout << apr << endl;
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
