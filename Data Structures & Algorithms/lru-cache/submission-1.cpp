class LRUCache {
public:
    int cap;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    void moveToHead(int key, int value){
        cacheList.erase(cacheMap[key]);
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        int value = cacheMap[key]->second;
        moveToHead(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            moveToHead(key, value);
            return;
        }

        if(cacheList.size() == cap){
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey);
            cacheList.pop_back();
        }

        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};
