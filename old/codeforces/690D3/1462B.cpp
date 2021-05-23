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
		string s;
		regex c1("(.*)(2020)");
		regex c2("(2)(.*)(020)");
		regex c3("(20)(.*)(20)");
		regex c4("(202)(.*)(0)");
		regex c5("(2020)(.*)");
		cin >> s;
		if (regex_match(s,c1) || regex_match(s,c2) || regex_match(s,c3) || regex_match(s,c4) || regex_match(s,c5)) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}
