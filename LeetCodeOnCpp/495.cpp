class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int len = timeSeries.size();
		if (len < 1)
			return 0;
		int ret = 0;
		for (int i = 0; i < len - 1; i++) {
			ret += min(timeSeries[i + 1] - timeSeries[i], duration);
		}
		ret += duration;
		return ret;
	}
};