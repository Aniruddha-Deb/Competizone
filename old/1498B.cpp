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
		int n, w;
		cin >> n >> w;
		deque<int> A(n);
		for (int i=0; i<n; i++) {
			cin >> A[i];
		}

		int x = (int)log2(w);
		sort(A.begin(), A.end());
		int h = 0;
		while (!A.empty()) {
			int s = A.back();
			int p = A.back();
			A.pop_back();
			while (s <= w && !A.empty()) {
				p = A.back();
				s += p;
				A.pop_back();
			}
			if (A.empty()) {
				h++;
				break;
			}
			s -= p;
			A.push_back(p);
			while (s <= w && !A.empty()) {
				p = A.front();
				s += p;
				A.pop_front();
			}
			s -= p;
			A.push_front(p);
			h++;
		}
		cout << h << endl;
	}
	return 0;
}
