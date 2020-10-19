#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n,k;
		cin >> n;
		set<int> sticks;
		for (int i=0; i<n; i++) {
			cin >> k;
			sticks.insert(k);
		}
		cout << sticks.size() << endl;
	}
	return 0;
}
