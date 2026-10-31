class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        backtrack(nums, 0, sol, res);
        return res;
    }

    void backtrack(vector<int>& nums, int index, vector<int> sol, vector<vector<int>>& res){
        if(index == nums.size()){
            res.push_back(sol);
            return;
        }

        sol.push_back(nums[index]);
        backtrack(nums, index+1, sol, res);
        sol.pop_back();
        backtrack(nums, index+1, sol, res);
    }
};
