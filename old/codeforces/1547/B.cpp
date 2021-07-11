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
	deque<char> V(s.begin(), s.end());

	char pc = s.length()+97;
//	cout << pc << " ";

	while (V.size() > 1 && ((V.front() == pc-1) || (V.back() == pc-1))) {
		if (V.front() == pc-1) {
			pc = V.front();
			V.pop_front();
		}
		else {
			pc = V.back();
			V.pop_back();
		}
	}

	if (V.front() == 'a' && V.size() == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
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