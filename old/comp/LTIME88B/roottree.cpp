#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, u, v;
		cin >> n;
		int *arr = (int*)calloc(n, sizeof(int));
		for (int i=0; i<n-1; i++) {
			cin >> u >> v;
			arr[v-1]++;
		}
		int nops = 0;
		for (int i=0; i<n; i++) {
			if (arr[i] == 0) nops++;
		}

		cout << nops-1 << endl;
	}
	return 0;
}
