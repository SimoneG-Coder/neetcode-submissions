class Solution {
public:
//LOGIC: the last opening bracket must be immediately followed by its corresponding closing bracket
    bool isValid(string s) {
        //use s stacl to store the opening brackets so that you can access the last opening bracket
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' ||
              s[i]=='[' ||
              s[i]=='{') st.push(s[i]);    //push in stack if opening bracket
            else{    //if closing bracket
                if(st.empty()) return false;    //if there are more closing brackets than opening, stack will already be empty
                if ((st.top()=='(' && s[i]==')') ||
                   (st.top()=='[' && s[i]==']') ||
                   (st.top()=='{' && s[i]=='}')) st.pop();
                else return false;
            }
        }
        return st.empty();    //if there are more opening brackets than closed, stack will not be empty
    }
};
