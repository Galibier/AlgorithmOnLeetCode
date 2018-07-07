class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int i = 0, n = bits.size() - 1;
		while (i < n) 
			i += bits[i] + 1;
		return i == n;
	}
};