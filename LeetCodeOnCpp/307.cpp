class NumArray {
private:
	int *BIT;
	int size;
	int sum(int x) {
		int ret = 0;
		while (x) {
			ret += BIT[x];
			x -= (x&-x);
		}
		return ret;
	}
public:
	NumArray(vector<int> nums) {
		size = nums.size();
		BIT = (int*)malloc(sizeof(int)*(size + 1));
		memset(BIT, 0, sizeof(int)*(size + 1));
		for (int i = 0; i < size; i++)
			update(i, nums[i]);
	}

	void update(int i, int val) {
		i++;
		val -= sum(i) - sum(i - 1);
		while (i <= size) {
			BIT[i] += val;
			i += (i&-i);
		}
	}

	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
*/