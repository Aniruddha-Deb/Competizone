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
		vi a;
		map<int, ll> sums;
		int temp;
		for (int i=0; i<n; i++) {
			cin >> temp;
			sums[temp] += temp;
		}

		ll msum = 0;
		int num = 0;
		for (auto p : sums) {
			if (p.second > msum) {
				msum = p.second;
				num = p.first;
			}
			else if (p.second == msum) {
				num = p.first;
			}
		}

		cout << num << " " << msum << endl;
	}
	return 0;
}
