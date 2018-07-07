class NumArray {
public:
    NumArray(vector<int> nums) {
        pref.assign(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) 
            pref[i + 1] = nums[i] + pref[i];
    }
    
    int sumRange(int i, int j) {
        return pref[j + 1] - pref[i];
    }
private:
    vector<int> pref; 
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */