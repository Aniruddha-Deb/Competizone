#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int n;
	cin >> n;
	vi A(n);
	vector<bool> O(n,false);
	forn(n) {
		cin >> A[i];
		if (A[i]) O[i] = true;
	}

	vi A1F = A;
	vector<bool> O1F = O;
	ll ans_1_fwd = 0;
	forn(n) {
		if (!A1F[i] && !O1F[i]) {
			for (int j=1; i-j >= 0 || i+j < n; j++) {
				if (i-j >= 0 && A1F[i-j]) {
					O1F[i] = true;
					A1F[i-j] = 0;
					ans_1_fwd += j;
					break;
				}
				else if (i+j < n && A1F[i+j]) {
					O1F[i] = true;
					A1F[i+j] = 0;
					ans_1_fwd += j;
					break;
				}
			}
		}
	}

	A1F = A;
	//forn(n) cout << A1F[i] << " ";
	//cout << endl;
	O1F = O;
	ll ans_1_bkwd = 0;
	for (int i=n-1; i>=0; i--) {
		if (!A1F[i] && !O1F[i]) {
			for (int j=1; i-j >= 0 || i+j < n; j++) {
				if (i-j >= 0 && A1F[i-j]) {
					O1F[i] = true;
					A1F[i-j] = 0;
					ans_1_bkwd += j;
					break;
				}
				else if (i+j < n && A1F[i+j]) {
					O1F[i] = true;
					A1F[i+j] = 0;
					ans_1_bkwd += j;
					break;
				}
			}
		}
	}

	vi A0 = A;
	vector<bool> O0 = O;
	ll ans_0_fwd = 0;
	forn(n) {
		if (A0[i]) {
			// look for a seat backwards
			for (int j=1; i-j >= 0 || i+j < n; j++) {
				if (i-j >= 0 && !O0[i-j]) {
					O0[i-j] = true;
					ans_0_fwd += j;
					break;
				}
				else if (i+j < n && !O0[i+j]) {
					O0[i+j] = true;
					ans_0_fwd += j;
					break;
				}
			}
		}
	}

	A0 = A;
	O0 = O;
	ll ans_0_bkwd = 0;
	for (int i=n-1; i>=0; i--) {
		if (A0[i]) {
			// look for a seat backwards
			for (int j=1; i-j >= 0 || i+j < n; j++) {
				if (i-j >= 0 && !O0[i-j]) {
					O0[i-j] = true;
					ans_0_bkwd += j;
					break;
				}
				else if (i+j < n && !O0[i+j]) {
					O0[i+j] = true;
					ans_0_bkwd += j;
					break;
				}
			}
		}
	}

	ll ans[] = {ans_1_fwd, ans_1_bkwd, ans_0_fwd, ans_0_bkwd};
	//forn(4) cout << ans[i] << " ";
	//cout << endl;
	cout << *min_element(ans, ans+4) << endl;
	return 0;
}
