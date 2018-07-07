class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		int index1 = 0, index2 = tmp.size() - 1;

		while (index1 < index2) {
			if (tmp[index1] + tmp[index2] > target) 
				index2--;
			else if (tmp[index1] + tmp[index2] < target) 
				index1++;
			else 
				break;
		}

		vector<int> ret;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == tmp[index1])
				ret.push_back(i);
			else if (nums[i] == tmp[index2])
				ret.push_back(i);
		}
		if (ret[0] > ret[1])
			swap(ret[0], ret[1]);
		return ret;
	}
};