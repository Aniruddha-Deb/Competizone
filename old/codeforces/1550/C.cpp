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

	int nsa = 2*n-1;
	for (int i=0; i<n-2; i++) {
		if (abs(A[i]-A[i+2]) != abs(A[i]-A[i+1])+abs(A[i+1]-A[i+2])) {
			nsa++;
		}
	}
	for (int i=0; i<n-3; i++) {
		if (A[i+1] > A[i] && A[i+1] > A[i+2] && A[i+1] > A[i+3] && A[i+1] > A[i+2] && A[i] > A[i+2] && A[i+3] > A[i+2]) {
			nsa++;
		}
		else if (A[i+1] < A[i] && A[i+1] < A[i+2] && A[i+1] < A[i+3] && A[i+1] < A[i+2] && A[i] < A[i+2] && A[i+3] < A[i+2]) {
			nsa++;
		}
	}
	cout << nsa << endl;
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