#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		if (n == 1) {
			int k;
			cin >> k;
			cout << k << endl;
		}
		else if (n == 2) {
			int k1, k2;
			cin >> k1 >> k2;
			if (k1 > k2) cout << k1 << endl;
			else cout << k2 << endl;
		}
		else if (n == 3) {
			int k1, k2, k3;
			cin >> k1 >> k2 >> k3;
			int A1 = k1 > k2 + k3 ? k1 : k2 + k3;
			int A2 = k2 > k1 + k3 ? k2 : k1 + k3;
			int A3 = k3 > k2 + k1 ? k3 : k2 + k1;
			if (A1 < A2 && A1 < A3) cout << A1 << endl;
			else if (A2 < A1 && A2 < A3) cout << A2 << endl;
			else cout << A3 << endl;
		}
		else if (n == 4) {
			vector<int> v;
			for (int i=0; i<4; i++) {
				int k;
				cin >> k;
				v.push_back(k);
			}
			int *A = (int*)malloc(sizeof(int)*7);
			A[0] = v[0] > v[1] + v[2] + v[3] ? v[0] : v[1] + v[2] + v[3];
			A[1] = v[1] > v[0] + v[2] + v[3] ? v[1] : v[0] + v[2] + v[3];
			A[2] = v[2] > v[1] + v[0] + v[3] ? v[2] : v[1] + v[0] + v[3];
			A[3] = v[3] > v[1] + v[2] + v[0] ? v[3] : v[1] + v[2] + v[0];
			A[4] = v[1] + v[2] > v[0] + v[3] ? v[1] + v[2] : v[0] + v[3];
			A[5] = v[1] + v[3] > v[0] + v[2] ? v[1] + v[3] : v[0] + v[2];
			A[6] = v[3] + v[2] > v[0] + v[1] ? v[3] + v[2] : v[0] + v[1];
			int min = A[0];
			for (int i=1; i<7; i++) {
				if (A[i] < min) min = A[i];
			}
			cout << min << endl;
			free(A);
		}
	}
	return 0;
}
