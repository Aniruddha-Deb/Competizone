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

bool search(int s, int i, int d, int k, vi& A, vector<bool>& visited) {
	visited[s] = true;
	if (s == i) return true;
	int j = s+1;
	while (j<A.size() && abs(A[j]-A[s])<(d-k)) j++;
	for (; j<A.size() && abs(A[j]-A[s])<=(d+k); j++) {
		// viable node; jump to this and search
		if (!visited[j] && search(j,i,d,k,A,visited)) return true;
	}
	j = s-1;
//	cout << "Going into second iter, s="<<s<<",j="<<j<<endl;
	while (j>0 && abs(A[j]-A[s])<(d-k)) j--;
	for (; j>0 && abs(A[j]-A[s])<=(d+k); j--) {
		// viable node; jump to this and search
//		cout << "Second iter, j="<< j<<endl;
		if (!visited[j] && search(j,i,d,k,A,visited)) return true;
	}
	return false;
}

void solve() {
	int n, q, s, d;
	cin >> n >> q >> s >> d;
	vi A(n+1);
	rep(i,0,n) cin >> A[i+1];

	while(q-- > 0) {
		int i,k;
		cin >> i >> k;
		vector<bool> v(n+1,false);
		if (search(s,i,d,k,A,v)) cout << "Yes" << endl;
		else cout << "No" << endl;
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