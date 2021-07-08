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

class Edge {

public:
	pi start;
	pi end;
	ll len;
	int dy;
	int dx;
	pair<double, double> mp;

	Edge(pi start, pi end) {
		this->start = start;
		this->end = end;
		this->dx = start.first - end.first;
		this->dy = start.second - end.second;
		this->len = ((ll)(this->dx))*(this->dx) + ((ll)(this->dy))*(this->dy);
		this->mp.first = start.first - ((double)dx)/2;
		this->mp.second = start.second - ((double)dy)/2;
	}

	bool sqdiag(Edge& e) {
		//cout << "(" << this->len << ", " << e.len << ")" << endl;
		return this->mp == e.mp && this->len == e.len && 
			((this->dy==0&&e.dx==0)||(this->dx==0&&e.dy==0)||(((double)this->dy*e.dy)/((double)this->dx*e.dx) == -1));
	}

	bool rectdiag(Edge& e) {
		return this->mp == e.mp && this->len == e.len;
	}
};

void solve() {
	vector<pi> pts;
	rep (i,0,8) {
		int x, y;
		cin >> x >> y;
		pts.push_back({x,y});
	}

	vector<Edge> edges;
	rep (i,0,8) {
		rep (j,i+1,8) {
			edges.push_back(Edge(pts[i], pts[j]));
		}
	}

	rep (i,0,28) {
		rep (j,i+1,28) {
			if (edges[i].sqdiag(edges[j])) {
				//cout << "Square diagonal found" << endl;
				// edges[i] and edges[j] form diagonals of a square
				vector<pi> rectpts;
				vector<pi> sqpts;
				for (pi pt : pts) {
					if (pt == edges[i].start || pt == edges[i].end || 
						pt == edges[j].start || pt == edges[j].end ) {
						sqpts.push_back(pt);
					}
					else {
						rectpts.push_back(pt);
					}
				}
				vector<Edge> otherpt_edges;
				vector<int> indexes;
				rep (k,0,4) {
					rep (l,k+1,4) {
						otherpt_edges.push_back(Edge(rectpts[k], rectpts[l]));
					}
				}
				rep (k,0,6) {
					rep (l,k+1,6) {
						if (otherpt_edges[k].rectdiag(otherpt_edges[l])) {
							// we have found both our square and rectangle
							cout << "YES" << endl;
							for (pi sqpt : sqpts) {
								cout << find(pts.begin(), pts.end(), sqpt) - pts.begin() + 1 << " ";
							}
							cout << endl;
							for (pi rectpt : rectpts) {
								cout << find(pts.begin(), pts.end(), rectpt) - pts.begin() + 1 << " ";
							}
							return;
						}
					}
				}
			}
		}
	}
	cout << "NO" << endl;
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