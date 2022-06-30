#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

set<int> range(int s, int e) {
	vector<int> v(e-s+1);
	rep (i,s,e+1) v[i-s] = i;
	return set<int>(v.begin(), v.end());
}

set<int> range_union(int s, int e, vector<int>& v) {
	set<int> S(v.begin(), v.end());
	set<int> r = range(s,e);
	S.insert(r.begin(), r.end());
	return S;
}

void solve() {
	int n;
	cin >> n;
	// guess fixed point
	int l = 1, r = n/2;
	while (l < r) {
		cout << "? " << l << " " << r << endl;
		vector<int> v(r+l-1);
		rep(i,0,r+l-1) cin >> v[i];
		set<int> ru = range_union(l,r,v);

		if ((ru.size() - (r-l+1))%2 == (r-l)%2) {
			// unmoved element lies here, in the left
			r = l + (r-l)/2;
			//cout << "Moving left" << endl;
		}
		else {
			//cout << "Moving right" << endl;
			int rp = r;
			r = r + (r-l)/2;
			l = rp + 1;
		}
	}
	cout << "? " << l << " " << r << endl;
	int a;
	cin >> a;
	if (a != l) {
		if (l > 1) {
			cout << "? " << l-1 << " " << l-1 << endl;
			cin >> a;
			if (a != l-1) cout << "! " << l+1 << endl;
			else cout << "! " << l-1 << endl;
		}
		else {
			cout << "? " << l+1 << " " << l+1 << endl;
			cin >> a;
			if (a != l+1) cout << "! " << l-1 << endl;
			else cout << "! " << l+1 << endl;
		}
	}
	else {
		cout << "! " << a << endl;
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
