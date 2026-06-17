class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";

        const auto &history = store[key];

        const auto it = upper_bound(history.begin(), history.end(), make_pair(timestamp, string("")), [](const pair<int, string> &a, const pair<int, string> &b){
            return a.first < b.first;
        });

        if(it == history.begin()) return "";

        return prev(it)->second;
    }
};
