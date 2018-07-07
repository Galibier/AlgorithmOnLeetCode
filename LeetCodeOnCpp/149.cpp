/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		unordered_map<double, int> slopes;
		int maxp = 0, n = points.size();
		for (int i = 0; i < n; i++) {
			slopes.clear();
			int duplicate = 1;
			for (int j = i + 1; j < n; j++) {
				if (points[j].x == points[i].x&&points[j].y == points[i].y) {
					duplicate++;
					continue;
				}
				double slope = (points[j].x == points[i].x) ? INT_MAX : (double)(points[j].y - points[i].y)*100.0 / (points[j].x - points[i].x);
				slopes[slope]++;
			}
			maxp = max(maxp, duplicate);
			for (auto slope : slopes)
				maxp = max(slope.second + duplicate, maxp);
		}
		return maxp;
	}
};
