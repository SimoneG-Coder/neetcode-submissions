class Solution {
public:
//LOGIC: use an unordered_map to keep track of frequency of each element in the given array
//Then use a priority queue to store elements based on their frequency
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num: nums){
            count[num]++;
        }
        //priority queue<type, container<type>, greater/less<type>> greater for minHeap(smallest on top)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto &val: count){
            //first element in priority queue gets higher priority, we want queue based on frequency
            minHeap.push({val.second, val.first});
            if(minHeap.size()>k)minHeap.pop();
        }
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
