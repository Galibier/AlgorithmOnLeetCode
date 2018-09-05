import java.util.*;

public class SubstringwithConcatenationofAllWords {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (words.length == 0) {
            return res;
        }
        Map<String, Integer> dict = new HashMap<>();
        Map<String, Integer> found = new HashMap<>();
        for (String word : words) {
            dict.put(word, dict.getOrDefault(word, 0) + 1);
        }
        int wordLen = words[0].length(), totalLen = words.length * wordLen, strLen = s.length();
        for (int start = 0; start < strLen - totalLen + 1; ++start) {
            int end = start;
            while (end < start + totalLen) {
                String substr = s.substring(end, end + wordLen);
                found.put(substr, found.getOrDefault(substr, 0) + 1);
                if (found.get(substr) > dict.getOrDefault(substr, 0)) {
                    break;
                }
                end += wordLen;
            }
            if (end == start + totalLen) {
                res.add(start);
            }
            found.clear();
        }
        return res;
    }
}
