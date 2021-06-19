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
	int a, b, c;
	cin >> a >> b >> c;
	if (c%2 == 0) {
		a = abs(a);
		b = abs(b);
		if (a > b) cout << ">" << endl;
		else if (a == b) cout << "=" << endl;
		else cout << "<" << endl;
	}
	else {
		if (a>=0 && b<0) {
			cout << ">" << endl;
		}
		else if (a<0 && b>=0) {
			cout << "<" << endl;
		}
		else if ((a<=0 && b<=0) || (a>=0 && b>=0)) {
			if (a > b) cout << ">" << endl;
			else if (a == b) cout << "=" << endl;
			else cout << "<" << endl;
		}
	}
	return 0;
}
