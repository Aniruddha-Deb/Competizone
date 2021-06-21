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
		vi A(2*n);
		for (int i=0; i<2*n; i++) cin >> A[i];
		sort(A.begin(), A.end());

		forn(n) {
			cout << A[i] << " " << A[n+i] << " ";
		}
		cout << endl;
	}
	return 0;
}
