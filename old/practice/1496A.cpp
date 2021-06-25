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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	deque<char> S;
	S.assign(s.begin(), s.end()); 
	if (2*k + 1 > n || 2*k == n) {
		cout << "NO" << endl;
		return;
	}
	if (k == 0) {
		cout << "YES" << endl;
		return;
	}

	while (S.size() > 1 && S.front() == S.back()) {
		S.pop_front();
		S.pop_back();
	}
	if ((n-S.size())/2 < k) cout << "NO" << endl;
	else cout << "YES" << endl;
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