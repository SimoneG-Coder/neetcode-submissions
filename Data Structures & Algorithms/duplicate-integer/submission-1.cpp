class Solution {
public:
//LOGIC: unordered_set contains unique elements so can be used to check for duplicates
    bool hasDuplicate(vector<int>& nums) {
        //The unordered set contains the elements iterated so far
        unordered_set<int> seenNum;
        for(int num:nums){
            //count(key) counts the number of elements but since unordered set only contains unique elements, it will return 0 or 1 here
            if(seenNum.count(num)) return true;
            //check if the number is there in unordered_set. If there=>duplicate found, otherwise insert that element in the set
            seenNum.insert(num);
        }
        return false;
    }
};
