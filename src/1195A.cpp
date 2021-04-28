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
	int n, k;
	cin >> n >> k;
	int A[1005];
	memset(A,0,1005*sizeof(int));
	
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		A[temp]++;
	}

	int nsets = ceil(((float)n)/2);
	int ess = 0;
	int oss_ec = 0;
	int oss_oc = 0;
	for (int i=1; i<=k; i++) {
		if (A[i]%2 == 0) {
			ess += A[i];
		}
		else {
			oss_ec += A[i]-1;
			oss_oc += 1;
		}
	}

	int sum = ess/2 + oss_ec/2 + oss_oc;
	if (sum > nsets) cout << ess/2 + oss_ec/2 + nsets << endl;
	else cout << ess+oss_ec+oss_oc << endl;

	return 0;
}
