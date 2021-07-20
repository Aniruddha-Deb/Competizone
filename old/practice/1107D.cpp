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
	int n;
	cin >> n;
	vector<vi> A(n,vi(n));
	rep(i,0,n) {
		for (int j=3; j<n; j+=4) {
			char c;
			cin >> c;
			int num = c-'0';
			if (c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F') {
				num = c-'A'+10;
			}
			rep(k,0,4) {
				A[i][j-k] = (num&(1<<k))>>k;
			}
		}
	}

	// for (vi v : A) {
	// 	for (int i : v) 
	// 		cout << i << " ";
	// 	cout << endl;
	// }

	vector<vi> sum(n,vi(n));
	sum[0][0] = A[0][0];
	rep(i,0,n) {
		rep(j,0,n) {
			if (i == 0 && j == 0) continue;
			else if (i == 0) sum[i][j] = A[i][j] + 0 + sum[i][j-1] - 0;
			else if (j == 0) sum[i][j] = A[i][j] + sum[i-1][j] + 0 - 0;
			else sum[i][j] = A[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}

	int maxi = 1;
	rep(i,2,n+1) {
		if (n%i == 0) {
			// check for squares
			bool possible = true;
			for (int j=0; j<n; j+=i) {
				for (int k=0; k<n; k+=i) {
					int s = 0;
					if (j == 0 && k == 0) s = sum[j+i-1][k+i-1];
					else if (j == 0) s = sum[j+i-1][k+i-1] - sum[j+i-1][k-1];
					else if (k == 0) s = sum[j+i-1][k+i-1] - sum[j-1][k+i-1];
					else s = sum[j+i-1][k+i-1] + sum[j-1][k-1] - (sum[j+i-1][k-1] + sum[j-1][k+i-1]);
					if (s != 0 && s != i*i) {
						//cout << "s is " << s << ", i*i is " << i*i << endl;
						possible = false;
						break;
					}
				}
				if (!possible) break;
			}
			if (possible) maxi = max(maxi,i);
		}
	}

	cout << maxi << endl;
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