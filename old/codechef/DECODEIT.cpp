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

char strToChar(string s) {
	char t = 0;
	for (int i=0; i<4; i++) {
		s[i] -= 48;
		t |= (s[i] << (3-i));
	}
	return t+97;
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		for (int i=0; i<(n/4); i++) {
			char c = strToChar(s.substr(4*i, 4));
			cout << c;
		}
		cout << endl;
	}
	return 0;
}
