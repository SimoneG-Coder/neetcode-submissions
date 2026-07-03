class Solution {
public:
//LOGIC: use a deque  to store the indices of elements(in descending order) where the elements of indices of deque are removed from the back till they are smaller han the current element
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> result;
      deque<int> dq;
      for(int right=0; right<nums.size(); right++){
        if(!dq.empty()&& dq.front()<right-k+1) dq.pop_front();    //If the first element is out of the window, pop it
        while(!dq.empty()&&nums[dq.back()]<=nums[right]) dq.pop_back();    //pop the elements from the back till they are smaller than the current element
        dq.push_back(right);    //push back the current element
        if(right>=k-1) result.push_back(nums[dq.front()]);    //push the max element(at the front) if the window size is equal to or greater than the given size
      }  
      return result;
    }
};
