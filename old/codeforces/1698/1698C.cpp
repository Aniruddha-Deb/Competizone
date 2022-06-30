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
	int n;
	cin >> n;
	vi A(n);
	int npos, nneg;
	npos = nneg = 0;
	int pos, neg;
	rep(i,0,n) {
		cin >> A[i];
		if (A[i] > 0) {
			npos++;
			pos = A[i];
		}
		else if (A[i] < 0) {
			nneg++;
			neg = A[i];
		}
	}
	if (n == 3 || n == 4) {
		set<int> S(A.begin(), A.end());
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				for (int k=j+1; k<n; k++) {
					if (S.find(A[i] + A[j] + A[k]) == S.end()) {
						cout << "NO" << endl;
						return;
					}
				}
			}
		}
		cout << "YES" << endl;
	}
	else if (npos == nneg && npos == 1 && pos == -neg) {
		cout << "YES" << endl;
	}
	else if ((npos == 1 && nneg == 0) || (nneg == 1 && npos == 0)) {
		cout << "YES" << endl;
	}
	else if (npos == 0 && nneg == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
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
