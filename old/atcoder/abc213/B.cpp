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
	vi A(n);
	rep(i,0,n) cin >> A[i];

	int sl = 0;
	int l = 1;
	if (A[l] < A[sl]) {
		int temp = l;
		l = sl;
		sl = temp;
	}
	rep(i,2,n) {
		if (A[i] > A[l]) {
			sl = l;
			l = i;
		}
		else if (A[i] < A[l] && A[i] > A[sl]) {
			sl = i;
		}
	}
	cout << sl+1 << endl;
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