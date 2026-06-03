class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& t:tokens){
            if(t =="+" || t =="-" || t =="*" || t =="/" ){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if(t =="+") st.push(a+b);
                else if(t =="-") st.push(a-b);
                else if(t =="*") st.push(a*b);
                else{
                    double division = static_cast<double>(a)/b;
                    st.push(division<0? static_cast<int>(ceil(division)): static_cast<int>(floor(division)));
                }
                
            }
            else st.push(stoi(t));
        }
        return st.top();
    }
};
