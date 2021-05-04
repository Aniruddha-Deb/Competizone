#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

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
		ll n;
		cin >> n;
		int nbits = 0;
		for (int i=0; i<64; i++) {
			if (n&(((ll)1)<<i)) {
				nbits++;
			}
		}
		cout << endl;
		cout << nbits << endl;
	}
	return 0;
}
