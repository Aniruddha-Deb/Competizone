#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

#ifdef DEBUG
#define debug(x) cout << x
#else
#define debug(x) 
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vi A(n);
		forn(n) cin >> A[i];
		sort(A.begin(), A.end());

		int mindiff = INT_MAX;
		int mdi = -1;
		for (int i=0; i<n-1; i++) {
			if (A[i+1]-A[i] < mindiff) {
				mindiff = A[i+1] - A[i];
				mdi = i;
			}
		}

		cout << A[mdi] << " ";
		for (int i=mdi+2; i<n; i++) cout << A[i] << " ";
		for (int i=0; i<mdi; i++) cout << A[i] << " ";
		cout << A[mdi+1] << endl;
	}
	return 0;
}
