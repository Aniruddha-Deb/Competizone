#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n;
	cin >> n;
	vi A(n), B(n);
	rep(i,0,n) cin >> A[i];
	rep(i,0,n) cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ms = 0;
	int is = 0;
	int i = n-1;
	for (; i>=n/4; i--) {
		ms += A[i];
		is += B[i];	
	}
	int a_t = n/4;
	int b_t = n/4;
	int nt = 0;
	while (ms < is && b_t >= 0) {
		nt++;
		cout << ms << " " << is << endl;
		if (i%4 == 3) {
			ms += 100-A[a_t++];
		}
		else {
			ms += 100;
			is += B[--b_t];
		}
		i--;
	}

	if (ms < is && A[a_t] == 100) {
		nt += ceil((float)(is-ms)/100) + ((is-ms)/300);
	}
	else if (ms < is) {
		int diff = is-ms;
		int nsum = ((is-ms)/300);
		for (int i=0; i<nsum && a_t-i>=0; i++) {
			cout << "adding " << A[a_t-i] << " to diff";
			diff += A[a_t-i];
		}
		nt += ceil((float)diff/100) + (diff/300);
	}

	cout << nt << endl;

}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}