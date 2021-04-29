#include <bits/stdc++.h>
using namespace std;

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
		int n, m, k;
		cin >> n >> m >> k;
		if ((m-1)+m*(n-1) == k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
