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
	int n;
	cin >> n;
	ll sum = 0;

	int temp;
	for (int i=0; i<n; i++) {
		cin >> temp;
		sum += temp;
	}

	int q = 0;
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> temp;
		sum = sum*2;
		sum = sum%MOD;
    	if (sum < 0) sum += MOD;
		cout << sum << endl;
	}
	return 0;
}
