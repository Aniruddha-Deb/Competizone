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
	int n,m,a;
	cin >> n >> m >> a;
	cout << (long long)(ceil(((double)m)/a)*ceil(((double)n)/a)) << endl;
	return 0;
}
