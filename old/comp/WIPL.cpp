#include <bits/stdc++.h>
using namespace std;

int** intMatrix(int n, int m) {
	int **A = (int**)malloc(sizeof(int*)*n);
	for (int i=0; i<n; i++) {
		A[i] = (int*)malloc(sizeof(int)*m);
	}
	return A;
}

void destroy_intMatrix(int **A, int n, int m) {
	for (int i=0; i<n; i++) {
		free(A[i]);
	}
	free(A);
}

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
		cin >> n >> k;
		priority_queue<int> H;
		for (int i=0; i<n; i++) {
			int u;
			cin >> u;
			H.push(u);
		}

		queue<int> S;

		int s = 0;
		int ts = 2*k + H.top();
		while (!H.empty() && s < ts) {
			int i = H.top();
			S.push(i);
			s += i;
			H.pop();
		}

		// problem is now reduced to finding two partitions of S with sums 
		// larger than k and with least number of boxes.

		for (

		int s1, s2, ops;
		s1 = s2 = ops = 0;
		while ((s1 < k || s2 < k) && !H.empty()) {
			if (s1 < k) {
				s1 += H.top();
				H.pop();
				ops++;
			}
			if (s2 < k) {
				s2 += H.top();
				H.pop();
				ops++;
			}
		}
		if (s1 < k || s2 < k) cout << -1 << endl;
		else cout << ops << endl;
	}
	return 0;
}
