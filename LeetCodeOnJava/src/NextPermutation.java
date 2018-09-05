public class NextPermutation {
    /**
     * 1) 先从后往前找到第一个不是依次增长的数，记录下位置k。比如例子中的3，对应的位置是1;
     * 2) 接下来分两种情况：
     *    (1) 如果上面的数字都是依次增长的，那么说明这是最后一个排列，下一个就是第一个，其实把所有数字反转过来即可(比如(6,5,4,3,2,1)下一个是(1,2,3,4,5,6));
     *    (2) 否则，如果k存在，从n-1开始往前找，找到下一个数就比k对应的数大的数字，然后两个调换位置，比如例子中的4。调换位置后得到(2,4,6,5,3,1)。
     *        最后把k之后的所有数字倒序，比如例子中得到(2,4,1,3,5,6), 这个即是要求的下一个排列。
     */
    public void nextPermutation(int[] nums) {
        int n = nums.length, k, l;
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums, 0, n - 1);
        } else {
            for (l = n - 1; l >= 0; l--) {
                if (nums[k] < nums[l]) {
                    break;
                }
            }
            swap(nums, k, l);
            reverse(nums, k + 1, n - 1);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    private void reverse(int[] nums, int l, int r) {
        while (l < r) {
            swap(nums, l++, r--);
        }
    }
}
