#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

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
	vi A(n);
	forn(n) cin >> A[i];

	vi pos;
	forn(n) if (A[i] == 1) pos.push_back(i);

	int k = pos.size();
	vector<vi> dp(n+1, vi(k+1, INT_MAX));
	dp[0][0] = 0;
	// yes, I understood and implemented the editorial solution :)
	for (int i=0; i<n; i++) {
		for (int j=0; j<=k; j++) {
			if (dp[i][j] == INT_MAX) continue;
			dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			if (j < k && A[i] == 0) {
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(pos[j]-i));
			}
		}
	}
	cout << dp[n][k] << endl;

	return 0;
}
