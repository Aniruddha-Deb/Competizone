#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

#ifdef DEBUG
#define debug(x) cout << x
#else
#define debug(x) 
#endif

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
	int A[1001];
	memset(A,0,sizeof(A));
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		A[temp]++;
	}
	bool permut = true;
	for (int i=1; i<=n; i++) {
		if (A[i] != 1) {
			permut = false;
			break;
		}
	}
	if (permut) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
