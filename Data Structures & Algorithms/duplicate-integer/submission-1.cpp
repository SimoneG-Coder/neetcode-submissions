class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seenNum;
        for(int num:nums){
            if(seenNum.count(num)) return true;
            seenNum.insert(num);
        }
        return false;
    }
};