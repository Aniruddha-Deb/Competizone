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
	const size_t size = 1100;
	bitset<size> DP;
	int A[] = {11, 111, 1111};
	DP.reset();
	for (int i : A) {
		if (i < size)
		DP.set(i);
	}
	for (int i=11; i<size; i++) {
		if (!DP.test(i)) continue;
		for (int j : A) {
			if (i+j < size) DP.set(i+j);
		}
	}
	//for (int i=0; i<size; i++) cout << i << " " << DP->test(i) << endl;
	while (t-- > 0) {
		int n;
		cin >> n;

		if (n < size && DP.test(n) == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
