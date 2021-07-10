#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 200005
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<int> G[MAX];
vector<bool> visited(MAX,false);
vector<int> colors(MAX);


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void backtrack(int p, int color) {

}

void dfs(int n, int parent, int depth) {
	visited[n] = true;
	if (G[n].empty()) {
		// leaf node, takahashi wins!
		colors[n] = 1;

	}
}

void solve() {
	int n;
	cin >> n;
	vector<string> W(n);
	rep(i,0,n) cin >> W[i];
	rep(i,0,n) {
		rep(j,0,n) {
			if (W[i].substr(W[i].length()-4).compare(W[j].substr(0,3)) == 0) {
				G[i].push_back(j);
			}
		}
	}

	dfs(0, 0);

	// nope. I tried.
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