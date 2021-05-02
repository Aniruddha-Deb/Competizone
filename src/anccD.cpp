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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int k, r1, r2, a1, a2;
		cin >> k >> r1 >> r2 >> a1 >> a2;
		int p = r1*r2/gcd(r1, r2);
		
		if (a1%r1 == 0 && a2%r2 == 0) cout << (k+abs(a2-a1))/p + 1 << endl;
		else cout << (k+abs(a2-a1))/p << endl;
	}
	return 0;
}
