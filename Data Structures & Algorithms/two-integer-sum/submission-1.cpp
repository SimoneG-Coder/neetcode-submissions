class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //store the number as key and index as value
        unordered_map<int, int> seenNums;
            for(int i=0; i<nums.size(); i++){
                //calculate the complement of the current number in the loop and check if it is there in the map
                int complement = target - nums[i];
                //find(key) returns an iterator so use end()
                if(seenNums.find(complement)!=seenNums.end()) return{seenNums[complement], i};
                //return{} returns an object of the reurn type
                seenNums[nums[i]] = i;  //if complement not found, insert the element and its index as it might be other number's complement
            }
            return{};   //returns empty object of return type;
    }
};
