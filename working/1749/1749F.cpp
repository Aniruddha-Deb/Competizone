#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define per(i, b, a) for (auto i = (b); i >= (a); i--)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void update(vector<vector<int>>& G, vector<int>& V, vector<vector<unordered_set<int>>>& D, int u, int v, int k, int d) {
    stack<int> S;
    // cout << G.size() << endl;
    vi parent(G.size(), -1);
    vector<bool> visited(G.size(), false);
    if (u == v) goto eval;
    S.push(u);
    visited[u] = true;
    while (!S.empty()) {
        auto n = S.top();
        S.pop();
        for (int l : G[n]) {
            if (l == v) {
                parent[l] = n;
                // cout << "Found v" << endl;
                goto eval;
            }
            if (!visited[l]) {
                visited[l] = true;
                S.push(l);
                parent[l] = n;
            }
        }
    }

eval:
    int n = v;
    vector<bool> updated(G.size(), false);
    while (n != -1) {
        for (int i=0; i<=d; i++) {
            for (int v : D[n][i]) {
                if (!updated[v]) {
                    // cout << v << " ";
                    updated[v] = true;
                    V[v] += k;
                }
            }
        }
        n = parent[n];
    }
    // cout << endl;

}

void update_D(vector<vector<int>>& G, vector<vector<unordered_set<int>>>& D, int v) {
    stack<pair<int,int>> S;
    vector<bool> visited(G.size(),false);
    S.push({v,0});
    visited[v] = true;
    while (!S.empty()) {
        auto p = S.top();
        S.pop();
        if (D[p.first][p.second].find(v) == D[p.first][p.second].end()) {
            D[p.first][p.second].insert(v);
            D[v][p.second].insert(p.first);
        }
        if (p.second < 20) {
            for (int n : G[p.first]) {
                if (!visited[n]) {
                    S.push({n,p.second+1});
                    visited[n] = true;
                }
            }
        }
    }
}

void solve() {
    // think of a DS which can efficiently store and update all the nodes at a 
    // distance k from some path
    int n;
    cin >> n;
    vector<vi> G(n+1, vi());
    // D stores a list of how far each node is from the given node
    vector<vector<unordered_set<int>>> D(n+1,vector<unordered_set<int>>(21,unordered_set<int>()));
    for (int i=1; i<=n; i++) {
        D[i][0].insert(i);
    }
    vi V(n+1, 0);
    rep(i,0,n-1) {
        int a, b;
        cin >> a >> b;
        // claim that one of a or b (at this stage, after connecting) is a leaf
        // node. 
        int l = (G[a].empty()) ? a : b;
        int t = (G[a].empty()) ? b : a;
        // we'll need to update the leaf node's distance map with the distance
        // map of the others, and vice versa
        for (int i=0; i<20; i++) {
            if (D[t][i].empty()) break;
            for (int n : D[t][i]) {
                D[l][i+1].insert(n);
                D[n][i+1].insert(l);
            }
        }
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // cout << n << endl;
    //
//    cout << "---" << endl;
//    for (int i=1; i<=n; i++) {
//        cout << i << ":" << endl;
//        for (int j=0; j<=4; j++) {
//            if (D[i][j].empty()) break;
//            cout << "    ";
//            for (int i : D[i][j]) {
//                cout << i << " ";
//            }
//            cout << endl;
//        }
//    }
//    cout << "---" << endl;
    
    int q;
    cin >> q;
    rep(qp, 0, q) {
        int qt;
        cin >> qt;
        if (qt == 1) {
            int idx;
            cin >> idx;
            cout << V[idx] << endl;
        }
        else {
            int u, v, k, d;
            cin >> u >> v >> k >> d;
            // update operation
            update(G,V,D,u,v,k,d);
        }
    }

}

int main() {
    init();
    int t = 1;
    // cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}
