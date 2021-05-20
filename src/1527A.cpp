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
		int mbi = 0;
		for (int i=31; i>=0; i--) {
			if (n & (1<<i)) {
				mbi = i;
				break;
			}
		}
		cout << ((1<<mbi) - 1) << endl;
			
	}
	return 0;
}
