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
	int n;
	cin >> n;
	vi A(n);
	forn(n) cin >> A[i];

	vi DP(n+1,-1);
	vi S(n+1,-1);
	DP[0] = 0;
	S[0] = 0;
	for (int i=0; i<n; i++) {
		if (i == 0 && A[i] > 0) {
			DP[i] = 1;
			S[i] = A[0];
		}
		for (int j=i-1; j>=0; j--) {
			if (A[i]+S[j] >= 0) {
				if (DP[j]+1 > DP[i]) {
					debug("Making "<<i<<" equal to DP["<<j<<"]+1="<<DP[j]+1<<endl);
					DP[i] = DP[j]+1;
					S[i] = A[i] + S[j];
				}
			}
		}
	}
	forn(n) cout << DP[i] << " ";
	cout << endl;
	forn(n) debug(S[i] << " ");
	debug(endl);
	cout << DP[n-1] << endl;
	return 0;
}
