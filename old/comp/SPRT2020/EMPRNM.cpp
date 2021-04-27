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

bool is_vowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
	init();
	string s;
	cin >> s;
	ostringstream out;
	for (int i=0; i<s.length(); i++) {
		char c = tolower(s[i]);
		if (!is_vowel(c)) out << '.' << c;
	}
	cout << out.str() << endl;
	return 0;
}
