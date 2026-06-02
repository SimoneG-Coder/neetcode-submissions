class Solution {
public:
//LOGIC: create an unordered_map that contains a sorted string as the key and the vector of unsorted strings as the values
//iterate through the given vector and sort the current string. Using the sorted string as a ket, insert the current string along with its anagrams
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
