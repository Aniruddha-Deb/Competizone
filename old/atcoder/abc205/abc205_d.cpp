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
	int n, q;
	cin >> n >> q;
	vector<ll> A(n);
	for (int i=0; i<n; i++) cin >> A[i];
	sort(A.begin(), A.end());
	for (int i=0; i<q; i++) {
		ll k;
		cin >> k;
		if (k < A[0]) cout << k << endl;
		else if (k > A[n-1]-n) cout << k+n << endl;
		else {
			int j;
			int sum = A[0]-1;
			for (j=0; j<n-1; j++) {
				int nb = A[j+1] - A[j] - 1;
				if (sum + nb >= k) {
					// found
					cout << (sum+nb)-k+A[j]+1 << endl;
					break;
				}
			}
		}
	}
			
	return 0;
}
