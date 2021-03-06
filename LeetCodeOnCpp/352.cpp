/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		auto it = st.lower_bound(Interval(val, val));
		int start = val, end = val;
		if (it != st.begin() && (--it)->end + 1 < val)
			it++;
		while (it != st.end() && val + 1 >= it->start&&val - 1 <= it->end) {
			start = min(start, it->start);
			end = max(end, it->end);
			it = st.erase(it);
		}
		st.insert(it, Interval(start, end));
	}

	vector<Interval> getIntervals() {
		vector<Interval> result;
		for (auto val : st)
			result.push_back(val);
		return result;
	}
private:
	struct cmp {
		bool operator()(Interval lhs, Interval rhs) {
			return lhs.start < rhs.start;
		}
	};
	set<Interval, cmp> st;
};

/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges obj = new SummaryRanges();
* obj.addNum(val);
* vector<Interval> param_2 = obj.getIntervals();
*/