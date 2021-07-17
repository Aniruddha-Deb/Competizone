#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int h, w, c;
	cin >> h >> w >> c;
	vector<vi> K(h,vi(w,0));
	rep(i,0,h) {
		rep(j,0,w) {
			cin >> K[i][j];
		}
	}

	// bruteforce for now
	ll minpath = (ll)1e18;

	rep(i,0,h) {
		rep(j,0,w) {
			int a1 = K[i][j];
			if (a1 > minpath) continue;
			int hdepth = (minpath/c)+i <= h ? minpath/c + i : h;
			int wdepth = (minpath/c)+j <= w ? minpath/c + j : w;
			rep(k,i,hdepth) {
				rep(l,j,wdepth) {
					if (i == k && j == l) continue;
					int a2 = K[k][l];
					if (a2 > minpath) continue;
					cout << "comparing ("<<i<<","<<j<<") & ("<<k<<","<<l<<")"<<endl;
					ll dist = ((ll)a1) + a2 + ((ll)c)*(abs(i-k)+abs(j-l));
					if (dist < minpath) minpath = dist;
				}
			}
		}
	}

	cout << minpath << endl;
	
}

int main() {
	init();
	int t = 1;
	//cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}