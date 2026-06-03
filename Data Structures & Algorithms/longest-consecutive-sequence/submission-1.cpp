class Solution {
public:
//LOGIC: use an unordered_set to store all elements and preventing duplicates
//only continue the iteration if an element is the header in its sequence
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLength = 0;
        for(int num: nums){
            if(st.find(num-1)!=st.end()) continue;
            int currentLength = 1;
            int val = num;
            while(st.find(val+1)!=st.end()){
                currentLength++;
                val++;
            }
            maxLength = max(currentLength, maxLength);
        }
        return maxLength;
    }
};
