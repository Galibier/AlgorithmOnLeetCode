class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<vector<vector<int>>> graph(N + 1, vector<vector<int>>());
		for (int i = 0; i < times.size(); i++)
			graph[times[i][0]].push_back({ times[i][1], times[i][2] });
		unordered_map<int, int> dis;
		for (int i = 0; i < N; i++)
			dis[i + 1] = INT_MAX;
		dis.erase(K);
		for (int i = 0; i < graph[K].size(); i++)
			dis[graph[K][i][0]] = graph[K][i][1];
		int res = 0;
		while (dis.size() != 0) {
			int target = -1, d = INT_MAX;
			for (auto p = dis.begin(); p != dis.end(); p++) 
				if (p->second < d) {
					d = p->second;
					target = p->first;
				}
			if (dis.size() != 0 && target == -1)
				return -1;
			res = max(res, d);
			dis.erase(target);
			for (int i = 0; i < graph[target].size(); i++) {
				if (dis.find(graph[target][i][0]) != dis.end()) {
					int tmp = d + graph[target][i][1];
					dis[graph[target][i][0]] = min(dis[graph[target][i][0]], tmp);
				}
			}
		}
		return res;
	}
};