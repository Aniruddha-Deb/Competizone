#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n;
	cin >> n;
	vi A(n);
	rep(i,0,n) cin >> A[i];

	map<int,vi> M;
	rep(i,0,n) M[A[i]].push_back(i);

	int ans = 0;
	int ans_a = 0;
	int l = 0;
	int r = 0;
	for (auto p: M) {
		int a = p.first;
		vi V = p.second;
		int s = 0;
		int a_l = V[0];
		int a_r = V[0];
		//cout << a << ": ";
		rep(i,0,V.size()) {
			if (i > 0) s -= (V[i]-V[i-1]-1);
			s += 1;
			a_r = V[i];
			//cout << s << " ";

			if (s < 1) {
				s = 1;
				a_l = V[i];
			}
			if (s > ans) {
				ans = s;
				ans_a = a;
				l = a_l;
				r = a_r;
			}
		}
		//cout << endl;

	}

	cout << ans_a << " " << l+1 << " " << r+1 << endl;

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
