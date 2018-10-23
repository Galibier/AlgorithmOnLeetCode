class Solution {
public:
    int climbStairs(int n) {
        int arr[3] = {0, 1, 2};
        for (int i = 3; i <= n; i++)
            arr[i % 3] = arr[(i - 1) % 3] + arr[(i - 2) % 3];
        return arr[n % 3];
    }
};