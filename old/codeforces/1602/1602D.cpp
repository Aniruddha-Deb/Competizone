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

vector<int> DP(300005,-1);
vector<int> np(300005,-1);
vector<bool> visit(300005,false);
int A[300005];
int B[300005];
int N;

int f(int n) {
	//cout << "at " << n << endl;
	if (n <= 0) {
		// reset visit
//		cout << "reached end, resetting begin" << endl;
//		fill(visit.begin(), visit.end(), false);
		return 0;
	}
	if (n > N) return -1;
	visit[n] = true;
	if (DP[n] != -1) {
		visit[n] = false;
		return DP[n];
	}
	int mj = -2;
	int npos = -1;
	for (int i=1; i<=A[n]; i++) {
		//visit[n] = true;
		int pos = n-i;
		if (n-i > 0) {
			// frog slips down
			pos += B[n-i];
		}
		if (!visit[pos]) {
			int nj = f(pos);
			//cout << "nj at " << pos << " = " << nj << endl;
			if ((nj < mj && mj >= 0 && nj >= 0) || (mj < 0 && nj >= 0)) {
				mj = nj;
				npos = n-i;
			}
		}
	}
	DP[n] = mj+1;
	np[n] = npos;
	visit[n] = false;
	return mj+1;
}

void solve() {
	int n;
	cin >> n;
	N = n;
	rep(i,1,n+1) cin >> A[i];
	rep(i,1,n+1) cin >> B[i];
	int ans = f(n);
	if (ans < 0) cout << -1 << endl;
	else {
		cout << ans << endl;
		int p = np[n];
		while (p > 0) {
			cout << p << " ";
			p = np[p+B[p]];
		}
		cout << 0 << endl;
	}
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}
