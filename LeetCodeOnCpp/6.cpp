#include "head_file.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2 || s.size() == 0)
            return s;
        int count = numRows * 2 - 2;
        vector<string> ret(numRows);
        for (int i = 0; i < s.size(); i++) {
            ret[min(i % count, count - i % count)] += s[i];
        }
        string ans;
        for (auto str:ret) {
            ans += str;
        }
        return ans;
    }
};