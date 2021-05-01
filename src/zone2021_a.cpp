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
	string s;
	cin >> s;
	
	int pos = 0;
	int occ = 0;
	string a = "ZONe";
	while ((pos=s.find(a,pos)) != string::npos) {
		occ++;
		pos += a.length();
	}
	cout << occ << endl;
	return 0;
}
