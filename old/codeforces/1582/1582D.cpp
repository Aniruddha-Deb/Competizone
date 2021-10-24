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
		// find 3 numbers of the same sign
		vector<int> B(n,0); 

		vector<pair<int,int>> vec = pos.size() >= 3 ? pos : neg;

		B[vec[0].second] = vec[1].first - vec[2].first;
		B[vec[1].second] = vec[2].first - vec[0].first;
		B[vec[2].second] = vec[0].first - vec[1].first;
		loc.erase(remove(loc.begin(), loc.end(), vec[0].second), loc.end());
		loc.erase(remove(loc.begin(), loc.end(), vec[1].second), loc.end());
		loc.erase(remove(loc.begin(), loc.end(), vec[2].second), loc.end());

		for (int i=0; i<n-3; i+=2) {
			B[loc[i]] = -A[loc[i+1]];
			B[loc[i+1]] = A[loc[i]];
		}

		for (int i : B) cout << i << " ";
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
