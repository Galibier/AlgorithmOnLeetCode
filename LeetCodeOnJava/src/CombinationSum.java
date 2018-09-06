import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSum {
    public List<List<Integer>> combinationSum(int[] nums, int target) {
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
                tmpRes.add(nums[i]);
                backtrack(res, tmpRes, nums, remain - nums[i], i);
                tmpRes.remove(tmpRes.size() - 1);
            }
        }
    }
}
