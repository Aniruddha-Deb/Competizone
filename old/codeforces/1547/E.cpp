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
	vi P(k), T(k);
	rep(i,0,k) {
		int temp;
		cin >> temp;
		P[i] = temp-1;
	}
	rep(i,0,k) cin >> T[i];
	vi temp(n,INT_MAX);

	for (int i=0; i<k; i++) {
		int p = P[i];
		int cpos = P[i];
		int tp = T[i];
		// front traversal
		while (cpos < n && (cpos-p)+tp < temp[cpos]) {
			temp[cpos] = tp+(cpos-p);
			cpos++;
		}
		// rear traversal
		cpos = P[i]-1;
		while (cpos >= 0 && (p-cpos)+tp < temp[cpos]) {
			temp[cpos] = tp+(p-cpos);
			cpos--;
		}
	}

	for (int i : temp) {
		cout << i << " ";
	}
	cout << endl;
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