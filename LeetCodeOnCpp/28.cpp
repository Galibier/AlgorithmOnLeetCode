#include "head_file.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        int m = haystack.size();
        int n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            if (needle == haystack.substr(i, n)) {
                return i;
            }
        }
        return -1;
    }
};