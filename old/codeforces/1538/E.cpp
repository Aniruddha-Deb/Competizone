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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int i;
	for (i=1; i<n; i++) {
		if (s[i] > s[0]) break;
		else if (s[i] == s[0]) {
			int j=1;
			while (i+j < n && s[i+j] == s[j]) {
				j++;
			}
			if (i+j < n && s[i+j] > s[j]) break;
			i += j;
		}
	}

	string sstr = s.substr(0,i);
	int len = sstr.length();
	for (int j=0; j<k/len; j++) {
		cout << sstr;
	}
	cout << sstr.substr(0,k-(k/len)*len) << endl;
	return 0;
}
