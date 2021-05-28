#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

#ifdef DEBUG
#define debug(x) cout << x
#else
#define debug(x) 
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void swap(vi& A, int i) {
	int i1 = i-1;
	int i2 = i;
	if (i == 0) i1 = A.size()-1;

	int temp = A[i1];
	A[i1] = A[i2];
	A[i2] = temp;
}

void recomp(vi& M, vi& A, int i) {
	if (i < 0) i = A.size()-i;
	if (i > A.size()-1) i = i-A.size();
	int i1 = i-1;
	int i2 = i+1;
	if (i == A.size()-1) i2 = 0;
	if (i == 0) i1 = A.size()-1;
	M[i] = A[i1] + A[i2];
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vi A(2*n);
		vi M(2*n);
		for (int i=0; i<2*n; i++) cin >> A[i];
		for (int i=0; i<2*n; i++) recomp(M,A,i);

		bool eq = true;
		do {
			forn (2*n) if (2*A[i] == M[i]) {
				swap(A,i);
				//cout << "Swapping at " << i << endl;
				recomp(M,A,i-1);
				recomp(M,A,i);
				recomp(M,A,i-2);
				recomp(M,A,i+1);
				/*for(int j=0; j<2*n; j++) cout << A[j] << " ";
				cout << endl;
				for(int j=0; j<2*n; j++) cout << M[j] << " ";
				cout << endl;*/
			}
			eq = true;
			forn (2*n) if (2*A[i] == M[i]) {
				//cout << "Eq is false going again" << endl;
				eq = false;
				break;
			}
		} while (!eq);

		forn(2*n) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
