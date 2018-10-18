#include "head_file.h"

class Solution {
public:
    int reverse(int x) {
        bool flag = true;
        if (x < 0)
            flag = false;
        long long num = abs(x), ret = 0;
        while (num) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        int res = (int) ret;
        if (ret != res)
            return 0;
        else
            return (flag ? 1 : -1) * ret;
    }
};