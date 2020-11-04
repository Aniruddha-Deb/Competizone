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
		int n, k, u;
		cin >> n >> k;
		vector<int> A;
		vector<int> dist_elem;
		long distElemSum = 0;
		for (int i=0; i<n; i++) {
			cin >> u;
			A.push_back(u);
			if (find(dist_elem.begin(), dist_elem.end(), u) == dist_elem.end()) {
				distElemSum += u;
				dist_elem.push_back(u);
			}
		}
		long long nSum = 0;
		for (int i=0; i<=n-k; i++) {
			long long sum = 0;
			set<int> addedElems;
			for (int j=i; j<k+i; j++) {
				sum += A[j];
				addedElems.insert(A[j]);
				// cout << A[j] << " ";
			}
			// cout << endl;
			long long ssdeSum = 0;
			for (int i : addedElems) {
				ssdeSum += i;
			}
			if (sum > nSum && ssdeSum == distElemSum) nSum = sum;
		}
		cout << nSum << endl;
	}
	return 0;
}
