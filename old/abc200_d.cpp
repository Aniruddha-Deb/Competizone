#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

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

	vi A(n);
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		A[i] = temp%200;
	}

	vi pos(205,0);
	vi l1, l2;
	int tot = 0;
	pos[0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=tot; j>=0; j--) {
			if (pos[j]) {
				pos[(j+A[i])%200]++;
			}
		}
		tot = (tot+A[i])%200;
	}

	for (int i=0; i<200; i++) {
		cout << pos[i] << endl;
	}
	return 0;
}
