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
	vi B(n/2);

	for (int i=0; i<n/2; i++) {
		cin >> B[i];
	}

	sort(B.begin(), B.end());

	int bmoves = 0;
	int wmoves = 0;
	for (int i=0; i<n/2; i++) {
		bmoves += abs(B[i] - (2*i+1));
		wmoves += abs(B[i] - (2*(i+1)));
	}

	cout << min(bmoves,wmoves) << endl;
	return 0;
}
