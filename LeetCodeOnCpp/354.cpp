bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs) {
	if (lhs.first == rhs.first)
		return lhs.second < rhs.second;
	return lhs.first < rhs.first;
}

class Solution {
private:

public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int N = envelopes.size();
		vector<int> dp(N, 1);
		int mx = (N == 0) ? 0 : 1;
		sort(envelopes.begin(), envelopes.end(), cmp);
		for (int i = 0; i < N; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
					dp[i] = max(dp[i], dp[j] + 1);
					mx = max(dp[i], mx);
				}
			}
		}
		return mx;
	}
};