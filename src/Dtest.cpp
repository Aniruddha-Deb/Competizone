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

int isprime(int n) {
	for (int i=2; i<n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

vi factorize(int n) {
	vi factors;
	for (int i=2; i<n; i++) {
		if (n%i == 0) factors.push_back(i);
	}
	return factors;
}

int main() {
	init();
	vi DP(101);

	cout << log2(536870912) << endl;
	for (int i=1; i<=1000; i++) {
		if (isprime(i)) DP[i] = 2;
		else {
			vi factors = factorize(i);
			bool aw = false;
			for (int f : factors) {
				if (DP[i-f] == 2) {
					aw = true;
					break;
				}
			}
			if (aw) DP[i] = 1;
			else DP[i] = 2;
		}
		cout << i << " -> ";
		if (DP[i] == 1) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}
	return 0;
}
