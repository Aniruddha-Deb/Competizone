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

void visit(vector<vi>& G, vector<bool>& visited, vi& L, int i) {
	visited[i] = true;
	for (int v : G[i]) {
		if (!visited[v]) visit(G,visited,L,v);
	}
	L.insert(L.begin(),i);
}

void assign(vector<vi>& Gt, vector<bool>& assigned, vector<vi>& cc, vi& Cmin, vi& C, int i, int r) {
	assigned[i] = true;
	cc[r].push_back(i);
	Cmin[r] = min(Cmin[r],C[i]);
	for (int v : Gt[i]) {
		if (!assigned[v]) assign(Gt,assigned,cc,Cmin,C,v,r);
	}
}

void solve() {
	int n;
	cin >> n;
	vi C(n+1);
	vi G(n+1);
	rep(i,0,n) cin >> C[i+1];
	rep(i,0,n) {
		int t;
		cin >> t;
		G[i+1] = t;
	}

	vector<bool> visited(n+1,false);
	int sum = 0;

	rep(i,1,n+1) {
		vi s;
		vi traversed;
		vector<bool> vit(n+1,false);
		if (!visited[i]) {
			s.push_back(i);
			vit[i] = true;
		}
		bool cyc_found = false;
		while (!s.empty()) {
			int h = s.back();
			traversed.push_back(h);
			s.pop_back();
			int u = G[h];
			if (!vit[u] && !visited[u]) {
				vit[u] = true;
				s.push_back(u);
			}
			else if (vit[u] && !visited[u]){
				//cout << "Aleady visited node " << u << endl;
				// visited, cycle found
				int mval = MOD;
				for (int j=0; j<traversed.size(); j++) {
					if (traversed[j] == u) {
						cyc_found = true;
					}
					if (cyc_found) {
						mval = min(mval, C[traversed[j]]);
					}
				}
				if (mval != MOD) sum += mval;
				for (int i=1; i<=n; i++) {
					if (vit[i]) visited[i] = true;
				}
				break;
			}
			if (cyc_found) break;
		}
	}

	cout << sum << endl;
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