public class CountingBits {
    public int[] countBits(int num) {
        int[] f = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            f[i] = f[i >> 1] + (1 & i);
        }
        return f;
    }

    public int[] countBits1(int num) {
        int[] bits = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i / 2];
            if (i % 2 == 1) {
                bits[i]++;
            }
        }
        return bits;
    }
}
