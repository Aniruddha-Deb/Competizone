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

// bool comp(vector<int>& a, vector<int>& b) {
// 	return a[1] > b[1];
// }

void solve() {
	int n, m;
	cin >> n >> m;
	vi A(m);
	vector<int> V(n);
	rep(i,0,m) {
		cin >> A[i];
		V[A[i]-1]++;
	}
	int mintasks = INT_MAX;

	rep(i,0,n) {
		if (V[i] < mintasks) mintasks = V[i];
	}
	cout << mintasks + min((m-mintasks*n)*2/n,  << endl;

	// sort by number of preferred tasks
	// sort(V.begin(), V.end(), comp);

	// rep(i,0,n) {
	// 	for (int i=)
	// }

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
