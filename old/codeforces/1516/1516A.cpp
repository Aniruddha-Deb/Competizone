#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n >> k;
		vector<int> A(n);
		for (int i=0; i<n; i++) {
			cin >> A[i];
		}

		for (int i=0; i<n-1; i++) {
			if (A[i] <= k) {
				A[n-1] += A[i];
				k -= A[i];
				A[i] = 0;
			}
			else {
				A[n-1] += k;
				A[i] -= k;
				k = 0;
				break;
			}
		}

		for (int i=0; i<n; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
