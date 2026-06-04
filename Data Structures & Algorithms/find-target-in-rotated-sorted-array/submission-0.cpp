class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        int minIdx = left;

        if(minIdx == 0) left = 0, right = n-1;
        else if(target >= nums[0] && target <= nums[minIdx-1]) left = 0, right = minIdx-1;
        else left = minIdx, right = n-1;

        while(left<=right){
            int mid = left + (right - left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};
