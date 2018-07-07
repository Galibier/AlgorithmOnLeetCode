class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret=0, len = nums.size();
        for(int i=0; i<=len; i++)
            ret^=i;
        for(int i=0; i<len; i++)
            ret^=nums[i];
        return ret;
    }
};