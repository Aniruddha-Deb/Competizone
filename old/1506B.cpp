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
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		bool fcs = false;
		int psi = 0;
		int nf = 0;
		int nb = 0;
		int fsi = s.find("*");
		int lsi = s.rfind("*");
		for (int i=fsi; i<n;) {
			if (s[i] == '*') {
				psi = i;
				nf++;
				int j = i+k;
				if (j >= n) break;
				while (s[j] != '*' && j > i+1) j--;
				i = j;
				continue;
			}
			i++;
		}
		if (psi != lsi) nf++;

		for (int i=lsi; i>=0; ) {
			if (s[i] == '*') {
				psi = i;
				nb++;
				int j = i-k;
				if (j < 0) break;
				while (s[j] != '*' && j < i-1) j++;
				i = j;
				continue;
			}
			i--;
		}
		if (psi != fsi) nb++;

		cout << min(nf, nb) << endl;
	}
	return 0;
}
