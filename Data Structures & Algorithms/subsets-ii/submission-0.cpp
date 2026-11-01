class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> sol;
        backtrack(nums, 0, sol, res);
        return res;
    }

    void backtrack(vector<int>& nums, int index, vector<int>& sol, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(sol);
            return;
        }

        sol.push_back(nums[index]);
        backtrack(nums, index+1, sol, res);
        sol.pop_back();

        int nextIdx = index+1;
        while(nextIdx < nums.size() && nums[nextIdx] == nums[index]) nextIdx++;
        backtrack(nums, nextIdx, sol, res);
    }
};
