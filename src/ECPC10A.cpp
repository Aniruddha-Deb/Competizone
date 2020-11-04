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
		int n, k;
		cin >> n;
		vector<int> A;
		long nums = 0;
		for (int i=0; i<n; i++) {
			cin >> k;
			for (int l : A) {
				int max = k>l ? k : l;
				if ((k^l) > max) nums++;
			}
			A.push_back(k);
		}
		cout << nums << endl;
	}
	return 0;
}
