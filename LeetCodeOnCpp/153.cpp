class Solution {
public:
	int findMin(vector<int> &num) {
		int left = 0;
		int right = num.size() - 1;

		while (left < right) {
			int mid = left + (right - left) / 2;

			if (num[mid] > num[right])
				left = mid + 1;
			else if (num[mid] < num[right]) 
				right = mid;
			else
				right--;
		}
		return num[left];
	}
};