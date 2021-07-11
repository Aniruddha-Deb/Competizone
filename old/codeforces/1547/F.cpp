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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}

void solve() {
	int n;
	cin >> n;
	vi A(n);
	rep(i,0,n) cin >> A[i];

	int allgcd = gcd(A[0],A[1]);
	for (int i=1; i<n; i++) {
		int pgcd = 1;
		if (i == n-1) pgcd = gcd(A[i], A[0]);
		else pgcd = gcd(A[i],A[i+1]);
		allgcd = gcd(allgcd, pgcd);
	}
	if (allgcd > 1) {
		//cout << "Common GCD " << allgcd <<" exists" << endl;
		rep(i,0,n) {
			A[i] /= allgcd;
		//	cout << A[i] << " ";
		}
		//cout << endl;
	}
	rep(i,0,n) {
		A.push_back(A[i]);
	}


	// for (int i : A) cout << i << " ";
	// 	cout << endl;

	// largest number of consec. ints with same non-one GCD
	// LOOP AROUND!!!
	int lpgcd = 0;
	for (int i=0; i<2*n-1; i++) {
		int npgcd = 0;
		int pgcd = gcd(A[i],A[i+1]);
		if (A[i] != 1) npgcd++;
		while (pgcd != 1 && i<2*n-1) {
			npgcd++;
			i++;
			int tgcd = gcd(A[i],A[i+1]);
			pgcd = gcd(pgcd, tgcd);
		}
		if (npgcd > lpgcd) lpgcd = npgcd;
	}

	cout << lpgcd << endl;
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