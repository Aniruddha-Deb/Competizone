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
	int n, m;
	cin >> n >> m;
	map<string,int> S;
	rep(i,0,n) {
		string s;
		cin >> s;
		S[s] += 1;
	}
	rep(i,0,m) {
		string r;
		cin >> r;
		int ctr=0;
		vector<int> qmpos;

		for (int i=0; i<r.length(); i++) {
			if (r[i] == '?') {
//				cout << i << endl;
				qmpos.push_back(i);
			}
		}

		string strs[] = {"", "a", "b", "c", "d", "e"};
		vector<string> parts;
		int si = 0;
		for (int p : qmpos) {
			parts.push_back(r.substr(si,p-si));
			si = p+1;
		}
		parts.push_back(r.substr(si,r.length()));
		string querystr = "";
		map<string, int> querystrs;
		for (int j=0; j<pow(6,parts.size()-1); j++) {
			querystr = "";
			for (int k=0; k<qmpos.size(); k++) {
				querystr += parts[k] + strs[(j/((int)pow(6,k)))%6];
			}
			querystr += parts[parts.size()-1];
			if (S[querystr] != 0 && querystrs[querystr] == 0) {
				//cout << "match for " << querystr << "found, adding " << S[querystr] << endl;
				ctr += S[querystr];				
				querystrs[querystr] += 1;
			}
		}
		cout << ctr << endl;
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