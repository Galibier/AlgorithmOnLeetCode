class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.length(), len2 = needle.length();
		if (len1 < len2)
			return -1;

		const unsigned long long B = 0x3f3f3f3f3;
		unsigned long long t = 1;
		for (int i = 0; i < len2; i++)
			t *= B;

		unsigned long long hhaystack = 0, hneedle = 0;
		for (int i = 0; i < len2; i++)
			hneedle = hneedle * B + needle[i];
		for (int i = 0; i < len2; i++)
			hhaystack = hhaystack * B + haystack[i];

		for (int i = 0; i + len2 <= len1; i++) {
			if (hneedle == hhaystack)
				return i;
			if (i + len2 < len1)
				hhaystack = hhaystack * B + haystack[i + len2] - haystack[i] * t;
		}
		return -1;
	}
};