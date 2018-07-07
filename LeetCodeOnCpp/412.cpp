class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ret_vec(n);
		for (int i = 1; i <= n; ++i) {
			if (0 == i % 3)
				ret_vec[i - 1] += "Fizz";
			if (0 == i % 5)
				ret_vec[i - 1] += "Buzz";
			if (ret_vec[i - 1].empty())
				ret_vec[i - 1] += to_string(i);
		}
		return ret_vec;
	}
};