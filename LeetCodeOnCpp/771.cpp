class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_set<char>pool(J.begin(), J.end());
		int ans = 0;
		for (auto & e : S)
			if (pool.count(e)) ans++;
		return ans;
	}
};