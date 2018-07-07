/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)
			return nullptr;
		auto copy = new UndirectedGraphNode(node->label);
		mp[node] = copy;
		queue<UndirectedGraphNode*> toVisit;
		toVisit.push(node);
		while (!toVisit.empty()) {
			auto cur = toVisit.front();
			toVisit.pop();
			for (auto neigh : cur->neighbors) {
				if (mp.find(neigh) == mp.end()) {
					auto neigh_copy = new UndirectedGraphNode(neigh->label);
					mp[neigh] = neigh_copy;
					toVisit.push(neigh);
				}
				mp[cur]->neighbors.push_back(mp[neigh]);
			}
		}
		return copy;
	}
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};