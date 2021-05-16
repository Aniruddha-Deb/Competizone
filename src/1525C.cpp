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
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, m;
		cin >> n >> m;
		vi A(n);
		int lc, rc;
		lc = rc = 0;
		vector<char> D(n);
		forn(n) cin >> A[i];
		forn(n) {
			cin >> D[i];
			if (D[i] == 'R') rc++;
			else lc++;
		}
		vi TC(n,-1)


		
	}
	return 0;
}
