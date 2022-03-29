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
	int n, q;
	cin >> n >> q;
	vector<pair<map<int,pi>,vi>> cars;
	for (int i=0; i<n; i++) {
		map<int,pi> mp;
		mp[i+1] = {-1,-1};
		cars.push_back({mp,vi(1,i+1)});
	}
	for (int t=0; t<q; t++) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			//cout << "Appending" << endl;
			int x, y;
			cin >> x >> y;
			int xp, yp;
			//pair<map<int,pi>,vi> xp, yp;
			int ypos;
			bool xf = false, yf = false;
			for (auto it = cars.begin(); it != cars.end(); it++) {
				auto cl = *it;
				if (cl.first.find(x) != cl.first.end()) {
					xp = it-cars.begin();
					xf = true;
					if (yf) break;
				}
				else if (cl.first.find(y) != cl.first.end()) {
					yp = it-cars.begin();
					ypos = it-cars.begin();
					yf = true;
					if (xf) break;
				}
			}
			for (auto p : cars[yp].first) {
				cars[xp].first.emplace(p);
			}
			for (auto k : cars[yp].second) {
				cars[xp].second.push_back(k);
			}
			cars.erase(cars.begin()+ypos);

			// for (auto i : cars[xp].second) {
			// 	cout << i << " ";
			// }
			// cout << endl;
		}
		else if (qt == 2) {
			int x, y;
			cin >> x >> y;
			int xp;
			int ypos;
			for (auto it = cars.begin(); it != cars.end(); it++) {
				auto cl = *it;
				if (cl.first.find(x) != cl.first.end()) {
					xp = it - cars.begin();
					break;
				}
			}
			pair<map<int,pi>,vi> yp;
			map<int,pi> ypmap;
			vi ypvec;
			bool deleting = false;
			int i=0;
			for (int i=0; i<cars[xp].second.size();) {
				if (cars[xp].second[i] == y) {
					deleting = true;
				}
				if (deleting) {
					int p = cars[xp].second[i];
					ypmap.emplace(*(cars[xp].first.find(p)));
					ypvec.push_back(p);
					cars[xp].first.erase(cars[xp].first.find(p));
					cars[xp].second.erase(cars[xp].second.begin()+i);
				}
				else {
					i++;
				}
			}
			cars.push_back({ypmap,ypvec});
		}
		else {
			int x;
			cin >> x;

			for (auto m : cars) {
				if (m.first.find(x) != m.first.end()) {
					cout << m.second.size() << " ";
					for (int i : m.second) {
						cout << i << " ";
					}
					cout << endl;
					break;
				}
			}
		}
		// for (auto i : cars) {
		// 	for (int j : i.second) {
		// 		cout << j << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

	}
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
