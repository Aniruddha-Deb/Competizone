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
	int n;
	cin >> n;
	vi A(n+1,0);
	rep(i,1,n+1) cin >> A[i];

	// DP[i][j] = max possible length of array of elements equal to i obtained
	// from applying operations to prefix ending at j
	// vector<vi> DP(n+1,vi(n+1,0));

	int ml = 0;

	for (int i=1; i<=n; i++) {

		stack<int> S;
		for (int j=1; j<=n; j++) {
			if (!S.empty() && A[j] == i) {
				// cleanup
				stack<int> S2;
				while (!S.empty() && S.top() != i) {
					if (!S2.empty() && S2.top() != S.top()) {
						S2.pop();
						S.pop();
					}
					else {
						S2.push(S.top());
						S.pop();
					}
				}
				// whatever's left in S2, push back
				while (!S2.empty()) {
					S.push(S2.top());
					S2.pop();
				}
			}
			S.push(A[j]);
		}

		stack<int> S2;
		while (!S.empty()) {
			if (!S2.empty() && S2.top() != S.top()) {
				S2.pop();
				S.pop();
			}
			else {
				S2.push(S.top());
				S.pop();
			}
		}

		// cout << S2.size() << " ";

		if (S2.size() > ml) ml = S2.size();

		// if (A[1] == i) DP[i][1] = 1;
		// for (int j=2; j<=n; j++) {
		// 	if (A[j] == i) {
		// 		if (A[j] != A[j-1]) DP[i][j] = DP[i][j-2]; // no diff, can remove
		// 		else DP[i][j] = DP[i][j-1] + 1;
		// 	}
		// 	else {
		// 		if (A[j] != A[j-1]) DP[i][j] = DP[i][j-2]; // can remove pair
		// 		else DP[i][j] = 
		// 	}
		// }
	}

	cout << ml << endl;
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
