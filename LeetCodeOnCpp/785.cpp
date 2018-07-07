class Solution {
public:
	bool isBipartite(vector<vector<int>>& graph) {
		vector<int> subset(graph.size(), 0);
		for (int i = 0; i < graph.size(); i++) {
			if (subset[i] == 0)
				subset[i] = 1;
			queue<int> connections;
			connections.push(i);

			while (!connections.empty()) {
				int node = connections.front();
				connections.pop();
				for (int j = 0; j < graph[node].size(); j++) {
					int otherNode = graph[node][j];
					if (subset[otherNode] == subset[node])
						return false;
					if (subset[otherNode] == 0) {
						subset[otherNode] = -subset[node];
						connections.push(otherNode);
					}
				}
			}
		}
		return true;
	}
};