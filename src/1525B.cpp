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
		int n;
		cin >> n;
		vi A(n);
		int one_pos = -1;
		int n_pos = -1;
		bool sorted = true;
		forn(n) {
			cin >> A[i];
			if (i > 0 && A[i] < A[i-1]) sorted = false;
			if (A[i] == 1) one_pos = i;
			if (A[i] == n) n_pos = i;
		}

		if (sorted) cout << 0 << endl;
		else if (one_pos == 0 || n_pos == n-1) cout << 1 << endl;
		else if (one_pos == n-1 && n_pos == 0) cout << 3 << endl;
		else cout << 2 << endl;
		
	}
	return 0;
}
