class Solution {
public:
//LOGIC: the product of elements except self is equal to product of elements to its right with elements to is left
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //if we want a vector with 'n' number of blocks, the size should be. The indexing should be 0 to n-1
        vector<int> output(n,1);

        int leftProduct = 1;
        for(int i=0; i<n; i++){
            output[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return output;
    }
};
