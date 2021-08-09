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
	int h, w, n;
	cin >> h >> w >> n;
	vector<pi> X;
	vector<pi> Y;
	rep(i,0,n) {
		int a,b;
		cin >> a >> b;
		X.push_back({i,a});
		Y.push_back({i,b});
	}

	sort(X.begin(), X.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});
	sort(Y.begin(), Y.end(), [](auto &left, auto &right) {
		return left.second < right.second;
	});

	int sub = X[0].second-1;
	X[0].second -= sub;
	rep(i,1,n) {
		if (X[i].second > X[i-1].second + sub + 1) {
			sub = X[i].second - X[i-1].second - 1;
		}
		X[i].second -= sub;
	}
	sub = Y[0].second-1;
	Y[0].second -= sub;
	rep(i,1,n) {
		if (Y[i].second > Y[i-1].second + sub + 1) {
			sub = Y[i].second - Y[i-1].second - 1;
		}
		Y[i].second -= sub;
	}

	sort(X.begin(), X.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});
	sort(Y.begin(), Y.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});

	rep(i,0,n) {
		cout << X[i].second << " " << Y[i].second << endl;
	}
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}