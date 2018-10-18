#include "head_file.h"

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;
        stack<char> ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                ans.push(s[i]);
            else if (s[i] == ')' && !ans.empty() && ans.top() == '(')
                ans.pop();
            else if (s[i] == ']' && !ans.empty() && ans.top() == '[')
                ans.pop();
            else if (s[i] == '}' && !ans.empty() && ans.top() == '{')
                ans.pop();
            else
                return false;
        }
        return ans.empty();
    }
};