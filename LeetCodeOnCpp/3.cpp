#include "head_file.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;

        int res = 0, begin = -1;
        vector<int> idx(256, -1);
        for (int i = 0; i != s.size(); i++) {
            if (idx[s[i]] > begin) {
                begin = idx[s[i]];
            }
            idx[s[i]] = i;
            res = max(res, i - begin);
        }

        return res;
    }
};