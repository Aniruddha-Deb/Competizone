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
	deque<char> t;
	bool fwd_dir = true;
	for (int i=0; i<(int)(s.length()); i++) {
		if (s[i] == 'R') fwd_dir = !fwd_dir;
		else if (fwd_dir) {
			if (!t.empty() && t.front() == s[i]) t.pop_front();
			else t.push_front(s[i]);
		}
		else {
			if (!t.empty() && t.back() == s[i]) t.pop_back();
			else t.push_back(s[i]);
		}
	}
	/*int i=0;
	while (i<((int)t.length()-1)) {
		if (i < 0) i=0;
		if (t[i] == t[i+1]) {
			t.erase(i,2);
			i--;
		}
		else i++;
		//cout << "i is now " << i << ", t.length()-1 = " << (t.length()-1) << ", i<t.length()-1 = " << (i<((int)(t.length())-1)) << endl;
	}*/
	
	while (!t.empty()) {
		if (fwd_dir) {
			cout << t.back();
			t.pop_back();
		}
		else {
			cout << t.front();
			t.pop_front();
		}
	}
	cout << endl;
	return 0;
}
