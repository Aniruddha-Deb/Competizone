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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		cout << 100 / gcd(100,n) << endl;
	}
	return 0;
}
