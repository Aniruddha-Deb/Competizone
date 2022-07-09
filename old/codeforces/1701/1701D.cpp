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

bool sort_first(pair<int,vector<int>>& a, pair<int,vector<int>>& b) {
	return a.second.size() < b.second.size();
}

void solve() {
	int n;
	cin >> n;
	vi B(n);
	rep(i,0,n) cin >> B[i];

	// stable marriage problem!

	vector<vector<int>> G(n,vector<int>());
	vector<int> A(n,0);
	for (int i=n; i>0; i--) {
		int j = i-1;
		int k = (B[j] != 0) ? i/B[j] : n;
		int l = i%(B[j]+1) == 0 ? (i/(B[j]+1))+1 : (i+B[j]+1)/(B[j]+1);
		while (k >= l) {
			G[k-1].push_back(i);
			k--;
		}
	}

	// stable marriage
	// vector<int> matched(n,false);
	vector<int> idxs(n,0);
	vector<bool> engaged(n,false);

	// for (int i=0; i<n; i++) {
	// 	cout << i+1 << ": ";
	// 	for (int j : G[i]) {
	// 		cout << j << " ";
	// 	} 
	// 	cout << endl;
	// }

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			// propose
			if (idxs[j] >= G[j].size()) {
				// no matching for this person!
				break;
			}
			if (!engaged[j]) {
				int pe = G[j][idxs[j]]-1;
				// accept/reject
				if (A[pe] != 0) {
					// engaged
					if (G[A[pe]-1].size() < G[j].size()) {
						idxs[j]++;
						//cout << j+1 << " Got rejected by " << pe+1 << endl;
					}
					else {
						// reject old
						int old = A[pe];
						engaged[A[pe]-1] = false;
						idxs[old-1]++;
						A[pe] = j+1;
						engaged[j] = true;	

						//cout << j+1 << " Got accepted by " << pe+1 << " and " << old << " got rejected " << endl;
					}
				}
				else {
					A[pe] = j+1;
					engaged[j] = true;
					//cout << j+1 << " Got accepted by " << pe+1 << endl;					
				}
			}
		}
		// for (int i : A) cout << i << " ";
		// 	cout << endl;		
	}

	for (int i : A) cout << i << " ";
		cout << endl;
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
