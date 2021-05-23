#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

void assign(int A[], int n1, int n2, int n3) {
	A[0] = n1;
	A[1] = n2;
	A[2] = n3;
}

int main() {
	init();
	int t;
	cin >> t;
	vector<string> uSets;
	vector<string> sets;
	while (t-- > 0) {
		int A[3];
		ostringstream out;
		cin >> A[0] >> A[1] >> A[2];
		sort(A, A+3);
		out << A[0] << " " << A[1] << " " << A[2];
		if (find(sets.begin(), sets.end(), out.str()) == sets.end()) {
			// unique str found
			uSets.push_back(out.str());
			sets.push_back(out.str());
		}
		else {
			uSets.erase(remove(uSets.begin(), uSets.end(), out.str()), uSets.end());
		}
	}

	cout << uSets.size() << endl;
	return 0;
}
