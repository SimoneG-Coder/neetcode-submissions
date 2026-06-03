class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vehicles(n);
        for(int i=0; i<n; i++){
            vehicles[i] = {position[i], speed[i]};
        }
        sort(vehicles.begin(), vehicles.end(), [](const auto &a, const auto &b){return a.first > b.first;});

        double maxTime = 0;
        int fleet = 0;
        for(int i=0; i<n; i++){
            double time = static_cast<double>(target - vehicles[i].first)/vehicles[i].second;
            if(time > maxTime){
                maxTime = time;
                fleet++;
            }
        }
        return fleet;
    }
};
