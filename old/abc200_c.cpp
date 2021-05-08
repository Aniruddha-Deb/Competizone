#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	init();
	int t;
	cin >> t;
	vi F(205,0);
	for (int i=0; i<t; i++) {
		int temp;
		cin >> temp;
		temp %= 200;
		F[temp]++;
	}

	ll nways = 0;
	for (int i=0; i<200; i++) {
		nways += (((ll)F[i])*(F[i]-1))/2;
	}
	cout << nways << endl;
	return 0;
}
