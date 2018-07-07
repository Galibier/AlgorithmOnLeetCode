class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n)
			return findMedianSortedArrays(nums2, nums1);
		int i, j, minIdx = 0, maxIdx = m, mid = (m + n + 1) / 2;
		while (minIdx <= maxIdx) {
			i = minIdx + (maxIdx - minIdx) / 2;
			j = mid - i;
			if (i > 0 && j < n && nums1[i - 1] > nums2[j])
				maxIdx = i - 1;
			else if (j > 0 && i < m && nums2[j - 1] > nums1[i])
				minIdx = i + 1;
			else
				break;
		}
		int num1;
		if (i == 0)
			num1 = nums2[j - 1];
		else if (j == 0)
			num1 = nums1[i - 1];
		else
			num1 = max(nums1[i - 1], nums2[j - 1]);

		if ((m + n) & 1)
			return num1;

		int num2;
		if (i == m)
			num2 = nums2[j];
		else if (j == n)
			num2 = nums1[i];
		else
			num2 = min(nums1[i], nums2[j]);

		return (num1 + num2) / 2.0;
	}
};