public class ImplementstrStr {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) {
            return 0;
        }
        if (needle.length() > haystack.length() || haystack.length() == 0) {
            return -1;
        }
        char[] ndl = needle.toCharArray();
        char[] hay = haystack.toCharArray();

        int[] next = new int[ndl.length];
        next[0] = -1;
        int k = -1;
        for (int i = 1; i < ndl.length; i++) {
            while (k > -1 && ndl[k + 1] != ndl[i]) {
                k = next[k];
            }
            if (ndl[k + 1] == ndl[i]) {
                k++;
            }
            next[i] = k;
        }

        k = -1;
        for (int i = 0; i < hay.length; i++) {
            while (k > -1 && ndl[k + 1] != hay[i]) {
                k = next[k];
            }
            if (ndl[k + 1] == hay[i]) {
                k++;
                if (k == ndl.length - 1) {
                    return i - k;
                }
            }
        }
        return -1;
    }
}
