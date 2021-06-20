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
		if (n%2 == 0) {
			if (log2(n) - floor(log2(n)) == 0 && ((int)log2(n))%2 == 1) cout << "Bob" << endl;
			else cout << "Alice" << endl;
		}
		else cout << "Bob" << endl;
	}
	return 0;
}
