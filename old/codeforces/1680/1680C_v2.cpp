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

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vi n0p(n+1,0);
	vi n1p(n+1,0);
	rep(i,1,n+1) {
		if (s[i-1] == '0') {
			n0p[i] = n0p[i-1]+1;
			n1p[i] = n1p[i-1];
		}
		else {
			n0p[i] = n0p[i-1];
			n1p[i] = n1p[i-1]+1;			
		}
	}

	for (int i : n0p) {
		cout << i << " ";
	}
	cout << endl;

	// two pointer search
	int min_score = n0p[n];
	for (int l=0,r=n; l<=r; ) {
		while (l<=r-1 and max(n1p[n]-n1p[r]+n1p[l], n0p[r]-n0p[l])<max(n1p[n]-n1p[r-1]+n1p[l], n0p[r-1]-n0p[l])) {
			r--;
			if (max(n1p[n]-n1p[r-1]+n1p[l], n0p[r-1]-n0p[l]) < min_score) {
				min_score = max(n1p[n]-n1p[r-1]+n1p[l], n0p[r-1]-n0p[l]);
				for (int i=l+1; i<=r; i++) cout << s[i]; cout << " ";
			}
		}
		l++;
	}

	cout << min_score << endl;


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
