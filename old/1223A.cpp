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
		int n;
		cin >> n;
		if (n == 2) cout << 2 << endl;
		else if (n%2 == 0) cout << 0 << endl;
		else cout << 1 << endl;
	}
	return 0;
}
