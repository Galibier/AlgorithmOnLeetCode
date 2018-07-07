class Solution {
public:
	string crackSafe(int n, int k) {
		int s = 1;
		for (int i = 0; i < n - 1; ++i)
			s *= k;

		std::vector<int> inds(s*k);
		for (int i = 0; i < k*s; ++i)
			inds[i] = i / s + (i%s)*k;

		std::string seq;
		for (int off = 0; off < s*k; ++off) {
			int c = off, tmp = 0;
			while (inds[c] != -1) {
				seq.push_back(c / s + '0');
				tmp = inds[c];
				inds[c] = -1;
				c = tmp;
			}
		}
		for (int i = 0; i < n - 1; ++i)
			seq.push_back(seq[i]);
		return seq;
	}
};