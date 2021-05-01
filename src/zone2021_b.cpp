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
	int n, D, H;
	cin >> n >> D >> H;
	double mx = 0.0;
	int d, h;
	for (int i=0; i<n; i++) {
		cin >> d >> h;
		double x = (((double)D)*h-d*H)/(D-d);
		if (x < 0) continue;
		else if (x > mx) mx = x;
	}

	cout << mx << endl;

	return 0;
}
