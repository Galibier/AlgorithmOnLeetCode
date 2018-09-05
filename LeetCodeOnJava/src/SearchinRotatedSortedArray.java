public class SearchinRotatedSortedArray {
    public int search(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long num = (nums[mid] < nums[0]) == (target < nums[0]) ? nums[mid] : target < nums[0] ? Long.MIN_VALUE : Long.MAX_VALUE;
            if (num > target) {
                hi = mid - 1;
            } else if (num < target) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    public int search1(int[] nums, int target) {
        int i = 0, j = nums.length - 1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] < target) {
                if (target > nums[j] && nums[mid] <= nums[j]) {
                    j = mid;
                } else {
                    i = mid + 1;
                }
            } else if (nums[mid] > target) {
                if (target < nums[i] && nums[mid] >= nums[i]) {
                    i = mid + 1;
                } else {
                    j = mid;
                }
            } else {
                return mid;
            }
        }
        return nums[i] == target ? i : -1;
    }
}
