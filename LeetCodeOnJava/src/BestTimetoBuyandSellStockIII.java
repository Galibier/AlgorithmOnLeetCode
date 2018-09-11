public class BestTimetoBuyandSellStockIII {
    public int maxProfit(int[] prices) {
        if (prices.length <= 1) {
            return 0;
        } else {
            int K = 2;
            int maxProf = 0;
            int[][] dp = new int[K + 1][prices.length];
            for (int k = 1; k <= K; k++) {
                int tmpMax = dp[k - 1][0] - prices[0];
                for (int i = 1; i < prices.length; i++) {
                    dp[k][i] = Math.max(dp[k][i - 1], prices[i] + tmpMax);
                    tmpMax = Math.max(tmpMax, dp[k - 1][i] - prices[i]);
                    maxProf = Math.max(dp[k][i], maxProf);
                }
            }
            return maxProf;
        }
    }
}
