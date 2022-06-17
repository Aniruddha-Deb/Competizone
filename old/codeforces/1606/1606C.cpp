#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vi A(n);
	rep(i,0,n) cin >> A[i];

	ll sum = 0;
	int i=0;
	string outnum = "";
	for (; i<n-1; i++) {
		ll diff = ((ll)pow(10,A[i+1]-A[i]) - 1);
		//cout << "d=" << diff << " ";
		if (sum + diff >= k+1) {
			outnum = to_string(k+1-sum) + outnum;
			sum += (k+1-sum);
			break;
		}
		else {
			outnum = to_string(diff) + outnum;
			sum += diff;
		}
		//cout << sum << " ";
	}
	if (sum <= k) outnum = to_string(k+1-sum) + outnum;
	// cout << endl;
	cout << outnum << endl;
}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}
