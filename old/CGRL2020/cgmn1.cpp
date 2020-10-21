#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

int main() {
	init();
	long long n, m;
	cin >> n >> m;
	long long fn=1,ln=n;
	long long sum = (n-1)*n/2 - 1;

	for (int i=0; i<m; i++) {
		long long k; cin >> k;
		if ( (k>1 && k<n) || k == fn || k == ln ) {
			long long t = fn;
			fn = ln;
			ln = t;
		}
		else {
			ln = k;
		}
		cout << sum + fn + ln << endl;
	}
	return 0;
}
