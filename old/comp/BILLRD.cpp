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
		int w, n, x, y;
		cin >> w >> n >> x >> y;
		
		if (x == y) cout << w << " " << w << endl;
		else {
			n %= 4;
			if (x > y) {
				if (n == 1) cout << w << " " << w-x+y << endl;
				if (n == 2) cout << w-x+y << " " << w << endl;
				if (n == 3) cout << 0 << " " << x-y << endl;
				if (n == 0) cout << x-y << " " << 0 << endl;
			}
			else {
				if (n == 1) cout << w-y+x << " " << w << endl;
				if (n == 2) cout << w << " " << w-y+x << endl;
				if (n == 3) cout << y-x << " " << 0 << endl;
				if (n == 0) cout << 0 << " " << y-x << endl;
			}
		}
	}
	return 0;
}
