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
	int n;
	cin >> n;

	int root = (int)sqrt(2*n)+2;

	vector<pi> greater;
	vector<pi> lesser;

	rep(i,0,n) {
		int temp;
		cin >> temp;
		if (temp >= root) greater.push_back({temp, i+1});
		else lesser.push_back({temp, i+1});
	}

	ll ctr = 0;

	for (auto i : lesser) {
		for (auto j : greater) {
			if (i.first*j.first == i.second+j.second) ctr++;
		}
	}

	for (int i=0; i<lesser.size(); i++) {
		for (int j=i+1; j<lesser.size(); j++) {
			if (lesser[i].first*lesser[j].first == lesser[i].second+lesser[j].second) ctr++;			
		}
	}

	cout << ctr << endl;
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