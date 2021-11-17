#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		// input
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> vec(m);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			vec[i] = make_pair(u, v);
		}
		// start from the end of the sequence of pairs in order to get the maximum
		// insert the pairs in a set to be able to check the distinct indices that we
		// have formed and both of the indices are distinct, then keep its i-th line as the answer
		set<int> s;
		vector<int> ans;
		for (int i = m - 1; i >= 0; i--) {
			if (s.find(vec[i].first) == s.end() && s.find(vec[i].second) == s.end()) {
				s.insert(vec[i].first);
				s.insert(vec[i].second);
				ans.push_back(i);
			}
		}
		// as a result of the operations above, the sequence of indices would be non-increasing
		// that's why we need to start from the end of the sequence up to the first to make it non-decreasing
		for (int i = (int) ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
