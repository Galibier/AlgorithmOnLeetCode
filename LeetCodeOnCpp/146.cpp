#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity):size(capacity) {}

    int get(int key) {
        if(cacheKeys.find(key)==cacheKeys.end()){
            return -1;
        }
        else{
            list<pair<int, int>>::iterator data = cacheKeys[key];
            cacheList.erase(data);
            cacheList.push_front(*data);
            cacheKeys[key]=cacheList.begin();
            return data->second;
        }
    }

    void put(int key, int value) {
        if(cacheKeys.find(key)!=cacheKeys.end()){
            list<pair<int, int>>::iterator data = cacheKeys[key];
            cacheList.erase(data);
            data->second = value;
            cacheList.push_front(*data);
            cacheKeys[key]=cacheList.begin();
        }
        else{
            if(cacheList.size()<size){
                cacheList.push_front(pair<int, int>(key, value));
                cacheKeys[key] = cacheList.begin();
            }
            else{
                cacheKeys.erase(cacheList.back().first);
                cacheList.pop_back();
                cacheList.push_front(pair<int, int>(key, value));
                cacheKeys[key] = cacheList.begin();
            }
        }
    }

private:
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheKeys;
    int size = 0;
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/