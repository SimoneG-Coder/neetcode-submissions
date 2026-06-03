class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> answer(n,0);
        for(int i=0; i<n; i++){
            int temp = temperatures[i];
            while(!st.empty() && st.top().first<temp){
                auto[stTemp, stIdx] = st.top();
                answer[stIdx] = i-stIdx;
                st.pop();
            }
            st.push({temp,i});
        }
        return answer;
    }
};
