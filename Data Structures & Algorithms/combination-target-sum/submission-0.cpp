class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        int currSum  = 0;
        backtrack(nums, target, 0, 0, sol, res);
        return res;
    }

    void backtrack(vector<int>& nums, int target, int index, int currSum, vector<int>& sol, vector<vector<int>>& res){
        if(currSum == target){
            res.push_back(sol);
            return;
        }

        if(index >= nums.size() || currSum > target) return;

        sol.push_back(nums[index]);
        backtrack(nums, target, index, currSum + nums[index], sol, res);
        sol.pop_back();
        backtrack(nums, target, index+1, currSum, sol, res);
    }
};
