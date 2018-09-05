public class CountandSay {
    private StringBuilder getNext(StringBuilder cur) {
        StringBuilder next = new StringBuilder();
        int count = 1;
        for (int i = 1; i <= cur.length(); i++) {
            if (i == cur.length() || cur.charAt(i) != cur.charAt(i - 1)) {
                next.append(count).append(cur.charAt(i - 1));
                count = 1;
            } else if (cur.charAt(i) == cur.charAt(i - 1)) {
                count++;
            }
        }
        return next;
    }

    public String countAndSay(int n) {
        if (n == 0) {
            return "";
        }

        StringBuilder cur = new StringBuilder("1");
        StringBuilder next;
        for (int i = 2; i <= n; i++) {
            next = getNext(cur);
            cur = next;
        }

        return cur.toString();
    }
}
