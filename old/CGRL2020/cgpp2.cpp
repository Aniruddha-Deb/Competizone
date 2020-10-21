#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

void print(vector<int> v) {
	for (int x : v) {
		cout << x << ", ";
	}
	cout << endl;
}

int main() {
	init();
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	string seq;
	for (int i=0; i<n; i++) {
		int t; cin >> t;
		arr.push_back(t);
	}
	cin >> seq;
	char cc = seq[0];
	int len = 1;
	long long sum = 0;
	vector<int> subseq;
	subseq.push_back(arr[0]);
	for (int i=1; i<n; i++) {
		if (seq[i] == cc) { 
			len++;
			subseq.push_back(arr[i]);
		}
		else {
			// char changes; do min calcs in subseq
			sort(subseq.begin(), subseq.end());
			int j = subseq.size() > k ? subseq.size()-k : 0;
			for (; j<subseq.size(); j++) {
				sum += subseq[j];
			}
			cc = seq[i];
			subseq.clear();
			subseq.push_back(arr[i]);
		}
	}
	// final work
	sort(subseq.begin(), subseq.end());
	int j = subseq.size() > k ? subseq.size()-k : 0;
	for (; j<subseq.size(); j++) {
		sum += subseq[j];
	}

	cout << sum << endl;
	return 0;
}
