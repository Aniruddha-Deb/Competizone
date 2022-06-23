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
	int n, m;
	cin >> n >> m;
	vector<vector<char>> M(n,vector<char>(m,0));
	vector<int> C_lr(m+n-1,0), C_rl(m+n-1,0);
	rep(i,0,n) {
		rep (j,0,m) {
			cin >> M[i][j];
			if (M[i][j] == 'B') {
				C_lr[i+j]++;
				C_rl[m-1-j+i]++;
			}
		}
	}

	int m_lr, M_lr, m_rl, M_rl;
	m_lr = M_lr = m_rl = M_rl = 0;
	bool m_lr_set, M_lr_set, m_rl_set, M_rl_set;
	m_lr_set = M_lr_set = m_rl_set = M_rl_set = false;
	rep (i,0,m+n-1) {
		if (C_lr[i] > 0 && !m_lr_set) {
			m_lr = i;
			m_lr_set = true;
		}
		if (C_lr[m+n-2-i] > 0 && !M_lr_set) {
			M_lr = m+n-2-i;
			M_lr_set = true;
		}		
		if (C_rl[i] > 0 && !m_rl_set) {
			m_rl = i;
			m_rl_set = true;
		}		
		if (C_rl[m+n-2-i] > 0 && !M_rl_set) {
			M_rl = m+n-2-i;
			M_rl_set = true;
		}
		if (m_lr_set && M_lr_set && m_rl_set && M_rl_set) break;
	}

	int rx4 = m_lr + M_lr + m_rl + M_rl - 2*(m-1);
	int cx4 = 2*(m_lr + M_lr) - rx4;
	//cout << rx4 << " " << cx4 << endl;

	if (rx4%4 == 2 && cx4%4 == 2) {
		if (M_rl - m_rl < M_lr - m_lr) cout << (rx4/4) + 2 << " " << (cx4/4) + 1 << endl;
		else cout << (rx4/4) + 1 << " " << (cx4/4) + 1 << endl;
	}
	else {
		cout << (rx4/4) + (rx4%4)/2 + 1 << " " << (cx4/4) + (cx4%4)/2 + 1 << endl;
	}
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
