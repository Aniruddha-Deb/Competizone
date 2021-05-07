#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

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
		int n;
		cin >> n;
		vi A(n);
		int mi = 0;
		int v_mi = INT_MAX;
		for (int i=0; i<n; i++) {
			cin >> A[i];
			if (A[i] < v_mi) {
				mi = i;
				v_mi = A[i];
			}
		}

		cout << n-1 << endl;
		for (int i=0; i<n; i++) {
			if (i == mi) continue;
			else if (i%2 == mi%2) cout << i+1 << " " << mi+1 << " " << v_mi << " " << v_mi << endl;
			else cout << i+1 << " " << mi+1 << " " << v_mi+1 << " " << v_mi << endl;
		}
	}
	return 0;
}
