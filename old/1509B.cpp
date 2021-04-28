#include <bits/stdc++.h>
using namespace std;

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
	while (t-- > 0) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string c = s;

		int nm = count(s.begin(), s.end(), 'M');

		if (nm != n/3) {
			cout << "NO" << endl;
			continue;
		}

		int tp_ctr = 0;
		int m_ctr = 0;
		int m_up = 0;
		for (int i=0; i<n && m_ctr+m_up <= n/3; i++) {
			if (s[i] == 'T') tp_ctr++;
			else if (s[i] == 'M' && tp_ctr > 0) {
				tp_ctr--;
				m_ctr++;
			}
			else {
				m_up++;
			}
		}
		if (m_up > 0) {
			cout << "NO" << endl;
			continue;
		}

		int tb_ctr = 0;
		m_ctr = m_up = 0;
		for (int i=n-1; i>=0 && m_ctr + m_up <= n/3; i--) {
			if (s[i] == 'T') tb_ctr++;
			else if (s[i] == 'M' && tb_ctr > 0) {
				tb_ctr--;
				m_ctr++;
			}
			else {
				m_up++;
			}
		}
		if (m_up > 0) cout << "NO" << endl;
		else cout << "YES" << endl;
				

	}
	return 0;
}
