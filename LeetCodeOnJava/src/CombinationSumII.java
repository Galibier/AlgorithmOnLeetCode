import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSumII {
    public List<List<Integer>> combinationSum2(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        backtrack(res, new ArrayList<>(), nums, target, 0);
        return res;
    }

    private void backtrack(List<List<Integer>> res, List<Integer> tmpRes, int[] nums, int remain, int start) {
        if (remain < 0) {
            return;
        } else if (remain == 0) {
            res.add(new ArrayList<>(tmpRes));
        } else {
            for (int i = start; i < nums.length; i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue;
                }
                tmpRes.add(nums[i]);
                backtrack(res, tmpRes, nums, remain - nums[i], i + 1);
                tmpRes.remove(tmpRes.size() - 1);
            }
        }
    }
}
