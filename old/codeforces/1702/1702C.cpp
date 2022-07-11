#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vi A(n);
	unordered_map<int,int> focc,locc;
	rep(i,0,n) {
		cin >> A[i];
		if (focc.count(A[i]) == 0) focc[A[i]] = i;
		locc[A[i]] = i;
	}

	//map<int,unordered_set<int>> stations;
	//vector<unordered_set<int>> suffixes(n,unordered_set<int>());
	// stations[A[n-1]] = unordered_set<int>();
	// stations[A[n-1]].insert(A[n-1]);

	// per(i,n-2,0) {
	// 	stations[A[i]] = stations[A[i+1]];
	// 	stations[A[i]].insert(A[i]);
	// }

	while(k--) {
		int a, b;
		cin >> a >> b;

		if (focc.count(a) == 0 || focc.count(b) == 0) cout << "NO" << endl;
		else if (focc[a] <= locc[b]) cout << "YES" << endl;
		else cout << "NO" << endl;

		// if (stations[a].count(b) > 0) {
		// 	cout << "YES" << endl;
		// }
		// else {
		// 	cout << "NO" << endl;
		// }
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
