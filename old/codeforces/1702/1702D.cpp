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

const bool comp_s(const pair<int,char>& a, const pair<int,char>& b) {
	return a.second < b.second;
}

const bool comp_f(const pair<int,char>& a, const pair<int,char>& b) {
	return a.first < b.first;
}

void solve() {
	string w;
	cin >> w;
	int n = w.length();
	vector<pair<int,char>> A(n);
	ll cost = 0;
	rep(i,0,n) {
		cost += (w[i]-'a'+1);
		A[i] = {i,w[i]};
	}
	int p;
	cin >> p;

	sort(A.begin(), A.end(), comp_s);

	while (cost > p) {
		char c = A[A.size()-1].second;
		cost -= (c-'a'+1);
		A.pop_back();
	}

	sort(A.begin(), A.end(), comp_f);
	for (auto c : A) {
		cout << c.second;
	}
	cout << endl;
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
