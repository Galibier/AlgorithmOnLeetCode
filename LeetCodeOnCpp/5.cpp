#include "head_file.h"

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;

        string max = s.substr(0, 1);
        for (int i = 0; i < s.size() - 1; i++) {
            helper(s, i, i);
            helper(s, i, i + 1);
        }
        return s.substr(low, len);
    }

private:
    int low, len;

    void helper(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[right] == s[left]) {
            left--;
            right++;
        }
        if (len < right - left - 1) {
            low = left + 1;
            len = right - left - 1;
        }
    }
};