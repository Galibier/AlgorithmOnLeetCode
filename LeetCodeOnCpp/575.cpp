class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		bitset<200001> hash;
		int count = 0;
		for (int i : candies) {
			if (!hash.test(i + 100000)) {
				count++;
				hash.set(i + 100000);
			}
		}
		int n = candies.size();
		return min(count, n / 2);
	}
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> ans(candies.begin(), candies.end());
        return min(ans.size(), candies.size()/2);
    }
};