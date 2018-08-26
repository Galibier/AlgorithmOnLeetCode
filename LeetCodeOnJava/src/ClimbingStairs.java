public class ClimbingStairs {
    public int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        int[] sum = {1, 2};
        for (int i = 3; i <= n; i++) {
            sum[(i + 1) % 2] = sum[0] + sum[1];
        }
        return sum[(n + 1) % 2];
    }
}
