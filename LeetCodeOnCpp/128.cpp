#include "head_file.h"

class Solution {
public:
    int longestConsecutive(const vector<int> &num) {
        unordered_set<int> s(num.begin(), num.end()), searched;
        int ret = 0;
        for (auto i : num) {
            if (searched.find(i) != searched.end())
                continue;
            searched.insert(i);
            int j = i - 1, k = i + 1;
            while (s.find(j) != s.end())
                searched.insert(j--);
            while (s.find(k) != s.end())
                searched.insert(k++);
            ret = max(ret, k - 1 - j);
        }
        return ret;
    }
};