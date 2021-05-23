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
	int n, q;
	cin >> n >> q;
	deque<int> C;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		C.push_back(temp);
	}
	int t;
	while (q-- > 0) {
		cin >> t;
		//for (int i=0; i<C.size(); i++) cout << C[i] << " ";
		//cout << endl;
		for (int i=0; i<C.size(); i++) {
			if (C[i] == t) {
				cout << i+1 << " ";
				C.erase(C.begin()+i);
				C.push_front(t);
				break;
			}
		}
	}
	cout << endl;

	return 0;
}
