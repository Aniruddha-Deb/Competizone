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
		int sum = 0;
		for (int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			sum += temp;
		}

		if (sum < n) cout << 1 << endl;
		else if (sum == n) cout << 0 << endl;
		else cout << sum-n << endl;
	}
	return 0;
}
