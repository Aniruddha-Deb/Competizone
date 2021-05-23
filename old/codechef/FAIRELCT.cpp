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
		int n, m;
		cin >> n >> m;
		priority_queue<int, vector<int>, greater<int>> A;
		priority_queue<int, vector<int>, less<int>> B;
		int sa, sb;
		sa = sb = 0;
		for (int i=0; i<n; i++) {
			int k;
			cin >> k;
			A.push(k);
			sa += k;
		}
		for (int i=0; i<m; i++) {
			int k;
			cin >> k;
			B.push(k);
			sb += k;
		}
		
		int nops = 0;
		while ((!A.empty() && !B.empty()) && sa <= sb) {
			int sat = A.top();
			int sbt = B.top();
			sa = (sa - sat + sbt);
			sb = (sb - sbt + sat);
			A.pop();
			B.pop();
			nops++;
		}
		if (sa <= sb) cout << "-1" << endl;
		else cout << nops << endl;
	}
	return 0;
}
