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
	unordered_map<int,int> A;
	vector<int> B;
	rep(i,0,n) {
		int k;
		cin >> k;
		B.push_back(k);
	}
	int a_max = INT_MIN;
	rep(i,0,n) {
		int k;
		cin >> k;
		if (k > a_max) a_max = k;
		if (A.count(k)) A[k] = A[k]+1;
		else A[k] = 1;
	}

	

	sort(B.begin(), B.end());

	bool not_match = false;
	per(i,n-1,0) {

		int u = B[i];

		if (__builtin_popcount(u) == 1) continue;

		bool match = false;
		//cout << "Converting " << u << endl;

		if (u%2 == 0) u /= 2;

		for (int j=1; ;j*=2) {
			int t;
			for (int k=0; k<j; k++) {
				t = u*j+k;
				//cout << t << " ";
				if (t > a_max) break;
				if (A.count(t) > 0 && A[t] > 0) {
					// match!
					//cout << "Converted " << B[i] << " to " << t << endl;
					A[t] = A[t]-1;
					B.pop_back();
					match = true;
					break;
				}
			}
			if (match) break;
			if (t > a_max) break;
		}		

		if (match) continue;


		// simple halving down
		u = B[i];
		while (u > 0) {
			if (A.count(u) > 0 && A[u] > 0) {
				// match!
				//cout << "Converted " << B[i] << " to " << u << endl;
				A[u] = A[u]-1;
				B.pop_back();
				match = true;
				break;
			}
			if (u%2 != 0) break;
			u /= 2;
		}

		// if (match) continue;
		// // largest element - try matching the spectrum
		// // first down, then up
		// t = B[i];
		// while (t > 0) {
		// 	if (A.count(t) > 0 && A[t] > 0) {
		// 		// match!
		// 		cout << "Converted " << B[i] << " to " << t << endl;
		// 		A[t] = A[t]-1;
		// 		B.pop_back();
		// 		match = true;
		// 		break;
		// 	}
		// 	if (t%2 == 1) t--;
		// 	else t /= 2;
		// }
		if (!match) {
			//cout << "Could not convert " << B[i] << endl;
			not_match = true;
			break;
		}
	}

	// for (int i : B) {
	// 	cout << i << " ";
	// }
	if (!not_match) cout << "YES" << endl;
	else cout << "NO" << endl;
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
