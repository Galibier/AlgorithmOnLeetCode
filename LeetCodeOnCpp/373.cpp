class Solution {
private:
	struct mycompare {
		bool operator()(const pair<int, int>& lhs, const pair<int, int>&rhs) {
			return lhs.first + lhs.second < rhs.first + rhs.second;
		}
	};
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> res;
		priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
		for (int i = 0; i < min((int)nums1.size(), k); ++i) {
			for (int j = 0; j < min((int)nums2.size(), k); ++j) {
				if (pq.size() < k)
					pq.push(make_pair(nums1[i], nums2[j]));
				else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
					pq.push(make_pair(nums1[i], nums2[j]));
					pq.pop();
				}
			}
		}
		while (!pq.empty()) {
			res.push_back(pq.top());
			pq.pop();
		}
		return res;
	}
};