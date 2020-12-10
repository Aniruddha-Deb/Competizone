#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

int fbrec(

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int nb, p;
		cin >> nb >> p;
		int **A = (int**)malloc(nb*sizeof(int*));
		
		float xm, ym;
		xm = ym = 0;

		for (int i=0; i<nb; i++) {
			A[i] = (int*)malloc(2*sizeof(int));
			cin >> A[i][0] >> A[i][1];
			xm += A[i][0];
			ym += A[i][1];
		}

		xm /= nb;
		ym /= nb;

		int fbx = A[0][0];
		int fby = A[0][1];
		for (int i=0; 
		
	}
	return 0;
}
