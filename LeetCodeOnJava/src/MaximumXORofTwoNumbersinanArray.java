import java.util.HashSet;

public class MaximumXORofTwoNumbersinanArray {
    public int findMaximumXOR(int[] nums) {
        int ans = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            HashSet set = new HashSet();
            int tmp = ans | (1 << i);
            //System.out.println(tmp);
            for (int j = 0; j < nums.length; j++) {
                int num = nums[j] & mask;
                if (set.contains(tmp ^ num)) {
                    ans = tmp;
                    break;
                }
                set.add(num);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {2, 3, 5, 25, 37, 23};
        MaximumXORofTwoNumbersinanArray tmp = new MaximumXORofTwoNumbersinanArray();
        tmp.findMaximumXOR(nums);
    }
}
