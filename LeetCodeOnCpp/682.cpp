class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> ret;
		for (string& op : ops) {
			if (op == "C") 
				ret.pop_back();
			else if (op == "D")
				ret.push_back(2 * ret.back());
			else if (op == "+")
				ret.push_back(ret.end()[-2] + ret.end()[-1]);
			else
				ret.push_back(stoi(op));
		}
		return accumulate(ret.begin(), ret.end(), 0);
	}
};