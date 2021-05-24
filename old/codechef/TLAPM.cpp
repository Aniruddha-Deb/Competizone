#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define forn(n) for(int i=0; i<(n); i++)

#ifdef DEBUG
#define debug(x) cout << x;
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

ll s1n(ll n) {
	return (n*(n+1))/2;
}

ll s1n2(ll n) {
	return (n*(n+1)*(2*n+1))/6;
}

ll sn(ll n1, ll n2) {
	return s1n(n2) - s1n(n1-1);
}

ll sn2(ll n1, ll n2) {
	return s1n2(n2) - s1n2(n1-1);
}

ll W(ll x, ll y) {
	return (((x+y)*(x+y-1))/2) - x + 1;
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		ll x1, x2, y1, y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
	
		ll ans = 0;
		for (ll i=y1; i<=y2; i++) {
			ans += W(x1,i);
		}
		for (ll i=x1+1; i<=x2; i++) {
			ans += W(i,y2);
		}
		//ll ans = ((x1*x1-3*x1)*(y2-y1+1))/2 + ((2*x1-1)*sn(y1,y2))/2 + sn2(y1,y2)/2 + (y2-y1+1)
		//		+ ((y2*y2-y2)*(x2-x1+1))/2 + ((2*y2-3)*sn(x1,x2))/2 + sn2(x1,x2)/2
		//		- W(x1,y2) + (x2-x1+1);

		cout << ans << endl;
	}
	return 0;
}
