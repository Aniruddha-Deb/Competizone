#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vi U(n);
		vi S(n);

		for (int i=0; i<n; i++) {
			cin >> U[i];
			U[i]--; // zero based indexing
		}

		for (int i=0; i<n; i++) {
			cin >> S[i];
		}

		
		vector<vi> T(n);
		for (int i=0; i<n; i++) {
			T[U[i]].push_back(S[i]);
		}
		for (int i=0; i<n; i++) {
			sort(T[i].begin(), T[i].end(), greater<int>());
		}

		vector<vector<ll>> P(n, vector<ll>(1,0));
		for (int i=0; i<n; i++) {
			for (int x : T[i]) {
				P[i].push_back(P[i].back()+x);
			}
		}

		vector<ll> ans(n);
		for (int i=0; i<n; i++) {
			for (int k=1; k<=T[i].size(); k++) {
				ans[k-1] += P[i][T[i].size()/k * k];
			}
		}

		for (ll a : ans) {
			cout << a << " ";
		}
		cout << endl;

	}
	return 0;
}
