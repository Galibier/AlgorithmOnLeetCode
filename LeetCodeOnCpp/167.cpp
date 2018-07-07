class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int index1 = 0, index2 = numbers.size() - 1;

		while (index1 < index2) {
			if (numbers[index1] + numbers[index2] > target) index2--;
			else if (numbers[index1] + numbers[index2] < target) index1++;
			else break;
		}

		vector<int> ans{ index1 + 1, index2 + 1 };
		if (ans[0] > ans[1])
			swap(ans[0], ans[1]);
		return ans;
	}
};