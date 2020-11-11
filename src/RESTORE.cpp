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
		int n;
		cin >> n;
		// need to reverse this algo lol
		int *A = (int*)malloc(sizeof(int)*n);
		for (int i=0; i<n; i++) {
			cin >> A[i];
		}
		for (int i=0; i<n; i++) {
			int index = i;
			for (int j=i+1; j<n; j++) {
				if (A[j]%A[i] == 0) index = j;
			}
			cout << index+1 << " ";
		}
		cout << endl;
		free(A);
	}
	return 0;
}
