class Solution {
public:
	int findIntegers(int num) {
		static int fb[31] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
			17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578 };
		if (num < 3) return num + 1;
		for (int bt = 29; bt >= 0; --bt) // bt should start from 30, but OJ accepts it from 29.
			if (num & (1 << bt)) 
				return num & (1 << (bt - 1)) ? fb[bt] : fb[bt - 1] + findIntegers((num & ~(1 << bt)));
	}
};