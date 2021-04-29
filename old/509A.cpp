#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int n;
	cin >> n;

	int A[10][10];
	memset(A,0,100*sizeof(int));
	for (int i=0; i<n; i++) {
		A[0][i] = 1;
		A[i][0] = 1;
	}
	for (int i=1; i<n; i++) {
		for (int j=1; j<n; j++) {
			A[i][j] = A[i-1][j] + A[i][j-1];
		}
	}
	cout << A[n-1][n-1] << endl;
		
	return 0;
}
