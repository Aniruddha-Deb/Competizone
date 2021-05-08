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
	ll sum = 0;
	ll i=3;
	for (; i<=3*n; i++) {
		if (sum + ((i-1)*(i-2))/2 >= k) break;
		else sum += ((i-1)*(i-2))/2;
		cout << "sum = " << sum << " ,i = " << i << endl;
	}
	ll j = 1;
	for (; j<=i-1; j++) {
		if (sum + (i-j) >= k) break;
		else sum += (i-j);
		cout << "sum = " << sum << " ,j = " << j << endl;
	}
	cout << k << endl;
	cout << sum << endl;
	cout << j << " " << k-sum << " " << i-j-(k-sum) << endl;
		
	return 0;
}
