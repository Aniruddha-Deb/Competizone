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
		int n;
		cin >> n;
		bool p = false;
		stack<int> s;
		for (int i=9; i>0; i--) {
			if (i >= n) {
				p=true;
				s.push(n);
				break;
			}
			else {
				n -= i;
				s.push(i);
			}
		}
		if (p) {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << endl;
		}
		else cout << "-1" << endl;

	}
	return 0;
}
