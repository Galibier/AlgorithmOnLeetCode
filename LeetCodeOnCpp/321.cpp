class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> result(k), tmp_result(k);
		vector<vector<int>> max_num1(k + 1), max_num2(k + 1);
		genDP(nums1, max_num1, k);
		genDP(nums2, max_num2, k);
		for (int i = 0; i <= k; i++) {
			if (max_num1[i].size() + max_num2[k - i].size() < k)
				continue;
			merge(tmp_result, max_num1, max_num2, i, k);
			if (result.empty() || smaller(result, tmp_result))
				result = tmp_result;
		}
		return result;
	}
private:
	void genDP(vector<int>& nums, vector<vector<int>>& max_num, int k) {
		int i, start;
		for (start = 0; nums.size() > 0; start = (i == 0 ? 0 : i - 1)) {
			if (nums.size() <= k)
				max_num[nums.size()] = nums;
			for (i = start; i + 1 < nums.size() && nums[i] >= nums[i + 1]; i++)
				;
			nums.erase(nums.begin() + i);
		}
	}

	void merge(vector<int>& tmp_result, vector<vector<int>>& max_num1, vector<vector<int>>& max_num2, int n, int k) {
		int i, j, ii, jj;
		for (i = j = 0; i < max_num1[n].size() && j < max_num2[k - n].size(); ) {
			for (ii = i, jj = j; ii < max_num1[n].size() && jj < max_num2[k - n].size() && max_num1[n][ii] == max_num2[k - n][jj]; ii++, jj++)
				;
			if (jj >= max_num2[k - n].size() || (ii<max_num1[n].size() && max_num1[n][ii]>max_num2[k - n][jj]))
				tmp_result[i + j] = max_num1[n][i++];
			else
				tmp_result[i + j] = max_num2[k - n][j++];
		}
		for (; i < max_num1[n].size(); i++)
			tmp_result[i + j] = max_num1[n][i];
		for (; i < max_num1[n].size(); i++)
			tmp_result[i + j] = max_num1[n][i];
		for (; j < max_num2[k - n].size(); j++)
			tmp_result[i + j] = max_num2[k - n][j];
	}

	bool smaller(vector<int>& result, vector<int>& tmp_result) {
		int i;
		for (i = 0; i < result.size() && result[i] == tmp_result[i]; i++)
			;
		if (i < result.size() && result[i] < tmp_result[i])
			return true;
		return false;
	}
};