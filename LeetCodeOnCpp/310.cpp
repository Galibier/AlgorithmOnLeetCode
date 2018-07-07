class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<unordered_set<int>> adj(n);
		for (pair<int, int> p : edges) {
			adj[p.first].insert(p.second);
			adj[p.second].insert(p.first);
		}
		vector<int> current;
		if (n == 1) {
			current.push_back(0);
			return current;
		}
		for (int i = 0; i < adj.size(); ++i) {
			if (adj[i].size() == 1) {
				current.push_back(i);
			}
		}
		while (true) {
			vector<int> next;
			for (int node : current) {
				for (int neighbor : adj[node]) {
					adj[neighbor].erase(node);
					if (adj[neighbor].size() == 1) 
						next.push_back(neighbor);
				}
			}
			if (next.empty()) 
				return current;
			current = next;
		}
	}
};