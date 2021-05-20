#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// Sol by rishabh:
/*
Call (i, j) a good pair if a(i) = a(j) and i < j. 

Rather than counting number of good pairs in each subarray, for each good pair count number of subarrays it is a part of.

for a good pair (i, j) this (i + 1)*(n - j) (0-indexed)

now let f(x) = {i such that a(i) = x}

you need to do sum (sum (i + 1)*(n - j) over all i < j in f(x)) over all x. 

its easy to see how to get the inner sum in |f(x)|.

now sum over all x, gg
*/

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vi A(n);
		map<int,int> M;
		forn(n) {
			cin >> A[i];
			M[A[i]] += 1;
		}
		// find and remove elements of frequency 1
		//for (auto p : M) {
		//	if (p.second < 2) {
		//		A.erase(remove(A.begin(), A.end(), p.first), A.end());
		//	}
		//}

		if (M.size() == n) {
			cout << 0 << endl;
			continue;
		}
		
		ll sum = 0;
		for (int i=n; i>=2; i--) {
			map<int,int> TM;
			for (int j=0; j<i; j++) {
				TM[A[j]] += 1;
			}
			//for (auto p : TM) {
			//	cout << "(" << p.first << "," << p.second << "), ";
			//}
			//cout << endl;
			//ll ssum = 0;
			for (int j=0; j<=n-i; j++) {
				//ll sasum = 0;
				//for (int k=j; k<=j+i-1; k++) {
				//	cout << A[k] << " ";
				//}
				//cout << "| ";
				// subarray is [j, j+i-1]
				for (auto p : TM) {
					if (p.second == 1) continue;
					sum += (((ll)p.second)*(p.second-1))/2;
				}
				TM[A[j]]--;
				if (j+i < n) TM[A[j+i]]++;
				//ssum += sasum;
			}
			//cout << "Sum = " << ssum << endl;
			//sum += ssum;
		}
		cout << sum << endl;
				
	}
	return 0;
}
