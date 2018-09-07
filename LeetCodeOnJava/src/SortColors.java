public class SortColors {
    public void sortColors(int[] nums) {
        int i = -1, count2 = 0;
        for(int j=0; j<nums.length; j++) {
            if(nums[j] == 0) {
                i++;
                nums[j] = 1;
                nums[i] = 0;
            }
            if(nums[j] == 2) {
                nums[j] = 1;
                count2++;
            }
        }
        for(int k=nums.length-1; k>=nums.length-count2; k--) {
            nums[k] = 2;
        }
    }
}
