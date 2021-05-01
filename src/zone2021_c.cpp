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
	int n;
	cin >> n;

	vector<int> P;
	vector<pair<int,vector<int>>> Q(3, vector<int>(5));
	for (int i=0; i<n; i++) {
		int temp;
		vector<int> tvals;
		cin >> temp;
		tvals.push_back(temp);
		int mval = temp;
		for (int j=0; j<4; j++) {
			cin >> temp;
			tvals.push_back(temp);
			if (temp < mval) mval = temp;
		}
		if (P.size() == 3 && mval > *min_element(P.begin(), P.end())) {
			*min_element(P.begin(), P.end()) = mval;

		}
		else {
			P.push_back(temp);
		}
			if (P[j].size() == 3 && temp > *min_element(P[j].begin(), P[j].end())) {
				*min_element(P[j].begin(), P[j].end()) = temp;
			}
			else {
				P[j].push_back(temp);
			}
		}
	}

	vector<ll> ans;
	for (int i=0; i<5; i++) {
		ll sum = 0;
		for (int j=0; j<3; j++) {
			sum += P[i][j];
		}
		ans.push_back(sum);
		cout << i << " value is " << sum << endl;
	}

	cout << *min_element(ans.begin(), ans.end()) << endl;
	return 0;
}
