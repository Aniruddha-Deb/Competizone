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
		int n;
		cin >> n;
		map<int,int> sumMap;
		for (int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			if (!sumMap[temp-i]) sumMap[temp-i] = 1;
			else sumMap[temp-i]++;
		}
		ll ans = 0;
		for (auto p : sumMap) {
			ll k = ((ll)p.second);
			ans += k*(k-1)/2;
		}
		cout << ans << endl;
	}
	return 0;
}
