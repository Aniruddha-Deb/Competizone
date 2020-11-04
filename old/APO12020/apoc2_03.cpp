#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

int main() {
	init();
	int t, k;
	cin >> t >> k;
	vector<int> A;
	for (int i=0; i<t; i++) {
		int u;
		cin >> u;
		A.push_back(u);
	}
	sort(A.begin(), A.end());
	int minDiff = INT_MAX;
	for (int i=0; i<=t-k; i++) {
		int diff = A[k+i-1]-A[i];
		//cout << "Diff is " << A[k+i-1] << " - " << A[i] << " = " << diff << endl;
		if (diff < minDiff) minDiff = diff;
	}
	cout << minDiff << endl;

	return 0;
}
