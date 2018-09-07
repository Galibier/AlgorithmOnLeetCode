public class MinimumWindowSubstring {
    public String minWindow(String s, String t) {
        if (s == null || t == null) {
            return "";
        }
        int countToBeContained = t.length(), minLen = Integer.MAX_VALUE, startIndex = -1;
        int[] dict = new int[128];
        for (char c : t.toCharArray()) {
            dict[c]++;
        }

        int fast = 0, slow = 0;
        while (fast < s.length()) {
            if (dict[s.charAt(fast++)]-- > 0) {
                countToBeContained--;
            }

            while (countToBeContained == 0) {
                if (dict[s.charAt(slow++)]++ == 0) {
                    countToBeContained++;
                }
                if (fast - slow + 1 < minLen) {
                    startIndex = slow - 1;
                    minLen = fast - slow + 1;
                }
            }
        }
        return startIndex == -1 ? "" : s.substring(startIndex, startIndex + minLen);
    }
}
