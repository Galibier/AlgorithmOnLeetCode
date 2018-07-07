class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.rbegin(), citations.rend());
		int h = 0, i = 0;
		for (int c : citations)
			h += c > i++;
		return h;
	}
};