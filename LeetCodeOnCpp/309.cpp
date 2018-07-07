class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int T_ik0_pre = 0, T_ik0 = 0, T_ik1 = INT_MAX;

		for (int price : prices) {
			int T_ik0_old = T_ik0;
			T_ik0 = max(T_ik0, T_ik1 + price);
			T_ik1 = max(T_ik1, T_ik0_pre - price);
			T_ik0_pre = T_ik0_old;
		}
		return T_ik0;
	}
};