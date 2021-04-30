#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
		int n, w, wr;
		cin >> n >> w >> wr;
		map<int, int> M;
		for (int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			M[temp] = M[temp]+1;
		}
		if (wr >= w) cout << "YES" << endl;
		else {
			ll sum = wr;
			for (auto p : M) {
				ll a = ((ll)p.first)*(p.second/2)*2;
				sum += a;
				if (sum >= w) break;
			}
			if (sum >= w) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
