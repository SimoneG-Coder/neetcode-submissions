class Solution {
public:
//LOGIC: Calculate the maximum possible rectangle involving each height
//If a height has taller or equal heights before or after it, its rectangle can be extended till before it unless we encounter a smaller height or stack is empty
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int height = heights[i];
            int start = i; //start index will calculate width and is i if the height can't be extended backwards
            while(!st.empty() && height < st.top().first){
                auto[h,j] = st.top(); //auto[h,j] auto initialises the variables
                st.pop(); //pop the stack if the height in array element is smaller than the one in stack top
                int width = i-j;
                maxArea = max(maxArea, h*width);
                start = j; //extend the index backwards till the larger previous heights
            }        
            st.push({height, start}); 
        }
        while(!st.empty()){ //when elements still left in the stack, continue empying it by using an imaginary height 0 of index after last element
            auto[h,j] = st.top();
            st.pop();
            int width = n-j;
            maxArea = max(maxArea, h*width);  
        } 
        return maxArea;   
    }
};
