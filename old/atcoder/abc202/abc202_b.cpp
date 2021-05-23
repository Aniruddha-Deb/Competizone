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
	string s;
	cin >> s;
	for (int i=s.length()-1; i>=0; i--) {
		if (s[i] == '6') cout << 9;
		else if (s[i] == '9') cout << 6;
		else cout << s[i];
	}
	cout << endl;
	return 0;
}
