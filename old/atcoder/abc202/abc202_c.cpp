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

int main() {
	init();
	int n;
	cin >> n;
	vector<vi> M(3,vi(n));
	vector<map<int, vi>> Mmap(3, map<int,vi>());
	for (int i=0; i<3; i++) {
		for (int j=0; j<n; j++) {
			cin >> M[i][j];
			Mmap[i][M[i][j]].push_back(j);
		}
	}

	ll ans = 0;
	for (auto pa : Mmap[0]) {
		int a = pa.first;
		int ni = pa.second.size();
		int nj = 0;
		if (Mmap[1].find(a) != Mmap[1].end()) {
			// B and A have a common element; check number of elements in C 
			// such that index matches
			// cout << a << " exists in B" << endl;
			for (int i : Mmap[1][a]) {
				if (Mmap[2].find(i+1) !=Mmap[2].end()) nj += Mmap[2][i+1].size();
			}
		}
		// cout << "ni = " << ni << ", nj = " << nj << endl;
		ans += ((ll)ni)*nj;
	}

	cout << ans << endl;

	return 0;
}
