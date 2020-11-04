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
		int n, m, k;
		cin >> n >> m;
		vector<vector<int>> A;
		vector<int> row;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> k;
				row.push_back(k);
			}
			A.push_back(row);
		}
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				cin >> k;
				
	}
	return 0;
}
