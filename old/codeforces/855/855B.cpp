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
	int n;
	ll p, q, r;
	cin >> n >> p >> q >> r;
	vi A(n);
	rep(i,0,n) cin >> A[i];
	vector<pi> G(n);
	G[0].first = A[0];
	G[n-1].second = A[n-1];
	vector<pi> S(n);
	S[0].first = A[0];
	S[n-1].second = A[n-1];
	rep(i,1,n) {
		G[i].first = max(G[i-1].first,A[i]);
		S[i].first = min(S[i-1].first,A[i]);
	}
	per(i,n-2,0) {
		G[i].second = max(G[i+1].second,A[i]);
		S[i].second = min(S[i+1].second,A[i]);
	}

	ll max = LONG_LONG_MIN;
	rep(i,0,n) {
		ll csum = 0;
		if (p < 0) { 
			csum += p*S[i].first; 
			//cout << p << "*" << S[i].first << " + ";
		} 
		else { 
			csum += p*G[i].first; 
			//cout << p << "*" << G[i].first << " + "; 
		}
		csum += q*A[i]; 
		//cout << q << "*" << A[i] << " + ";
		if (r < 0) { 
			csum += r*S[i].second; 
			//cout << r << "*" << S[i].second << " = ";
		}
		else { 
			csum += r*G[i].second; 
			//cout << r << "*" << G[i].second << " = "; 
		}

		//cout << csum << endl;

		if (csum > max) max = csum;
	}

	cout << max << endl;
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
