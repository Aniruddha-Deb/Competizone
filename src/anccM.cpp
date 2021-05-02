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
	string s;
	cin >> s;

	string s1 = s;
	int osf, esf;
	osf = esf = 0;
	for (int i=0; i<n-2; i+=2) {
		// odd
		if (s1[i] > s1[i+2]) {
			s1[i+2] = s1[i];
			osf++;
		}
	}
	for (int i=1; i<n-2; i+=2) {
		if (s1[i] < s1[i+2]) {
			s1[i+2] = s1[i];
			esf++;
		}
	}

	string s2 = s;
	int osb, esb;
	osb = esb = 0;
	for (int i=(n%2==0)?n-2:n-1; i>1; i-=2) {
		if (s2[i] < s2[i-2]) {
			s2[i-2] = s2[i];
			osb++;
		}
	}
	for (int i=(n%2==0)?n-1:n-2; i>1; i-=2) {
		if (s2[i] > s2[i-2]) {
			s2[i-2] = s2[i];
			esb++;
		}
	}

	int A[] = {osf+esf, osf+esb, osb+esf, osb+esb};
	cout << *min_element(A,A+4) << endl;
	return 0;
}
