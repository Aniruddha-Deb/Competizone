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
	ll n, k;
	cin >> n >> k;
	for (int i=0; i<k; i++) {
		if (n%200 == 0) n /= 200;
		else n = (n*1000)+200;
	}
	cout << n << endl;
	return 0;
}
