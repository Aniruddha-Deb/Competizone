#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false); // desynchronizes C and CPP IO
	cin.tie(NULL); // does not tie cin with cout (Input/Output happens independently)
}

int MSB(int x) {
	return (int)(log2(x));
}

int main() {
	init();
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, x;
		cin >> n >> x;
		vector<list<int>> A(32);
		vector<int> nums(n);

		for (int i=0; i<n; i++) {
			int k;
			cin >> k;
			nums[i] = k;
			for (int j=0; j<32; j++) {
				if ((k & (1<<j)) > 0) A[j].push_back(i);
			}
		}

		int i=0;
		for (int nops=0; nops<x && i<n;) { 
			if (nums[i] == 0) {
				i++;
				continue;
			}
			int p2 = MSB(nums[i]);
			// cout << "op " << nops << ", MSB of " << nums[i] << " is " << (1 << p2) << endl;
			if (A[p2].size() <= 1) {
				nums[i] ^= (1<<p2);
				nums[n-1] ^= (1<<p2);
				A[p2].pop_front();
				A[p2].push_back(n-1);
			}
			else {
				nums[i] ^= (1<<p2);
				A[p2].pop_front();
				nums[A[p2].front()] ^= (1<<p2);
				A[p2].pop_front();
			}
			nops++;
		}

		for (int i=0; i<n; i++) {
			printf("%d ", nums[i]);
		}
		printf("\n");
	}
	return 0;
}
