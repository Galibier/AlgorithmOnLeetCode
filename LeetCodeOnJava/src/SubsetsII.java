import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SubsetsII {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> each = new ArrayList<>();
        backtrace(res, each, 0, nums);
        return res;
    }

    private void backtrace(List<List<Integer>> res, List<Integer> each, int idx, int[] nums) {
        if (idx <= nums.length) {
            res.add(each);
        }
        int i = idx;
        while (i < nums.length) {
            each.add(nums[i]);
            backtrace(res, new ArrayList<>(each), i + 1, nums);
            each.remove(each.size() - 1);
            i++;
            while (i < nums.length && nums[i] == nums[i - 1]) {
                i++;
            }
        }
    }
}
