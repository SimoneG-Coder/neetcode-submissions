class Solution {
public:
//LOGIC: push integers in stack till you get an operator
//the element on top of stack should be element on right side of the operation
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
                    //use static_cast<type>(variable) for typecasting 
                    double division = static_cast<double>(a)/b;
                    //since we want the output for division to be close to 0, use floor division for positive results and ceil division for negative ones
                    st.push(division<0? static_cast<int>(ceil(division)): static_cast<int>(floor(division)));
                }
                
            }
            else st.push(stoi(t));
        }
        return st.top();
    }
};
