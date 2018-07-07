/*
// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};
*/
class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> map;
		std::transform(employees.begin(), employees.end(), std::inserter(map, map.end()), [&](Employee* element) {
			return std::make_pair(element->id, element);
		});
		return help(map, id);
	}

	int help(unordered_map<int, Employee*>& map, const int id) {
		return map[id]->importance + std::accumulate(map[id]->subordinates.begin(), map[id]->subordinates.end(), 0, [&](int sum, int id) {
			return sum + help(map, id);
		});
	}
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> map;
		for (const auto element : employees) {
			map[element->id] = element;
		}
		return help(map, id);
	}

	int help(unordered_map<int, Employee*>& map, const int id) {
		auto sum = map[id]->importance;
		for (const auto element : map[id]->subordinates) {
			sum += help(map, element);
		}
		return sum;
	}
};