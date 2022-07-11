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

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int nz = 0;
	rep(i,0,n) if (s[i] == '0') nz++;

	// cost = max(#0 left, #1 removed)
	// to minimize cost, minimize the number zeros left and number ones removed
	// ideally we want a string with lot of ones 

	// chomp ones till a zero is encountered, then zeros till a one is encountered

	int l=0, r=n-1;
	int min_cost = nz;
	int n1r = 0;
	//for (int i=l; i<=r; i++) cout << s[i]; cout << " ";
	while (l<=r) {
		int nlc = 0;
		int nlz = 0;
		int cl = l;
		while (s[cl] == '1' && cl<=r) {
			cl++; nlc++;
		}
		while (s[cl] == '0' && cl<=r) {
			cl++; nlz++;
		}

		// can't do this! has to be minimized with the right one....
		// ensure we're making the best move at every stage.
		
		//for (int i=l; i<=r; i++) cout << s[i]; cout << " ";
		
		int nrc = 0;
		int nrz = 0;
		int cr = r;
		while (s[cr] == '1' && l<=cr) {
			cr--; nrc++;
		}
		while (s[cr] == '0' && l<=cr) {
			cr--; nrz++;
		}

		int lmove = max(nz-nlz,n1r+nlc);
		int rmove = max(nz-nrz,n1r+nrc);
		int move = min(lmove,rmove);
		bool updated = false;

		if (move < min_cost) {
			min_cost = move;
			if (lmove < rmove) {
				nz -= nlz;
				n1r += nlc;
				l = cl;
			}
			else if (lmove == rmove) {
				if (nlc < nrc) {
					// do a left move
					nz -= nlz;
					n1r += nlc;
					l = cl;
				}
				else {
					nz -= nrz;
					n1r += nrc;
					r = cr;
				}
			}
			else {
				nz -= nrz;
				n1r += nrc;
				r = cr;
			}
			updated = true;
		}

		if (!updated) break;
		//for (int i=l; i<=r; i++) cout << s[i]; cout << " ";
	}

	cout << min_cost << endl;
}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}
