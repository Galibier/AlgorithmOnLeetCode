public class HouseRobberII {
    public int rob(int[] num) {
        if (num.length == 1) {
            return num[0];
        }
        return Math.max(rob(num, 0, num.length - 1), rob(num, 1, num.length));
    }

    private int rob(int[] num, int l, int r) {
        int rob = 0;
        int notrob = 0;
        for (int i = l; i < r; i++) {
            int currob = notrob + num[i];
            notrob = Math.max(notrob, rob);
            rob = currob;
        }
        return Math.max(rob, notrob);
    }
}
