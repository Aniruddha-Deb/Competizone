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

Rather than counting number of good pairs in each subarray, for each good pair 
count number of subarrays it is a part of.

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
		ll n;
		cin >> n;
		vi A(n);
		map<int,vi> M;
		forn(n) {
			cin >> A[i];
			M[A[i]].push_back(i);
		}

		ll sum = 0;
		for (auto p : M) {
			vi pos = p.second;
			int k = pos.size();
			ll sum_p = n*k*(k-1)/2;
			ll ij_sum = 0;
			ll ij_sum_temp = 0;
			for (int i=0; i<k; i++) {
				sum_p += n*pos[i]*(k-i-1);
				sum_p -= ((ll)i)*pos[i];
				ij_sum += ij_sum_temp*pos[i];
				ij_sum_temp += pos[i];
			}
			sum_p -= ij_sum;
			//cout << sum_p << ", "; 
			sum += sum_p;
			//cout << "Sum after " << p.first << " is " << sum << endl;
		}

		cout << sum << endl;
	}
	return 0;
}
