class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anaMap;
        for(string s:strs){
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            anaMap[sortedStr].push_back(s);
        }
        vector<vector<string>> result;
        for(auto& val: anaMap){
            result.push_back(val.second);
        }
        return result;
    }
};
