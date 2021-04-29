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
		map<int, vll> R;

		for (int i=0; i<n; i++) {
			cin >> U[i];
			int temp = U[i];
			if (R.find(temp) == R.end()) {
				R[temp] = vll();
			}
		}

		for (int i=0; i<n; i++) {
			ll temp;
			cin >> temp;
			R.find(U[i])->second.push_back(temp);
		}

		for (auto p : R) {
			sort(p.second.begin(), p.second.end(), greater<int>());
			for (int i=1; i<p.second.size(); i++) {
				p.second[i] += p.second[i-1];
			}
			R[p.first] = p.second;
		}

		for (int i=1; i<=n; i++) {
			ll s = 0;
			for (auto p : R) {
				vll Q = p.second;
				int l = Q.size();
				if (l-l%i > 0) s += Q[(l-l%i)-1];   
			}
			cout << s << " ";
		}
		cout << endl;

	}
	return 0;
}
