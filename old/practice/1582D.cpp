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

ll gcd(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	if (b == 0) return a;
	else return gcd(b,a%b);
}

void solve() {

	int n;
	cin >> n;
	vector<int> A(n);
	vector<int> loc(n);
	vector<pair<int,int>> pos,neg;
	rep(i,0,n) {
		loc[i] = i;
		cin >> A[i];
		if (A[i] > 0) pos.push_back({A[i],i});
		else neg.push_back({A[i],i});
	}

	if (n%2 == 0) {
		for (int i=0; i<n; i+=2) {
			cout << (-1)*A[i+1] << " " << A[i] << " ";
		}
		cout << endl;
	}
	else {

		ll n0 = A[1] - A[2];
		ll n1 = A[2] - A[0];
		ll n2 = A[0] - A[1];

		if (n0 == 0 && n1 == 0 && n2 == 0) {
			// vec parallel to (1,1,1)
			cout << "1 -2 1 ";
		}
		else {
			if (n0 == 0) {
				n0 = -2*A[2];
				n1 = n2 = A[0];
			}
			else if (n1 == 0) {
				n1 = -2*A[0];
				n0 = n2 = A[1];
			}
			else if (n2 == 0) {
				n2 = -2*A[1];
				n0 = n1 = A[2];
			}
			ll gcd_val = gcd(n0,gcd(n1,n2));
			cout << n0/gcd_val << " " << n1/gcd_val << " " << n2/gcd_val << " ";
		}
		for (int i=3; i<n; i+=2) {
			cout << (-1)*A[i+1] << " " << A[i] << " ";
		}
		cout << endl;

	}


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
