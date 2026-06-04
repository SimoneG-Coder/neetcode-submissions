class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int height = heights[i];
            int start = i;
            while(!st.empty() && height < st.top().first){
                auto[h,j] = st.top();
                st.pop();
                int width = i-j;
                maxArea = max(maxArea, h*width);
                start = j;
            }        
            st.push({height, start});
        }
        while(!st.empty()){
            auto[h,j] = st.top();
            st.pop();
            int width = n-j;
            maxArea = max(maxArea, h*width);  
        } 
        return maxArea;   
    }
};
