class Solution {
public:

    string encode(vector<string>& strs) {
        string answer = "";
        for(string str: strs){
            answer = answer + to_string(str.length()) + '#' + str;
        }
        return answer;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;
        while(i<s.length()){
            int j = i+1;
            while(j<s.length() && s[j]!='#') j++;
            int length = stoi(s.substr(i,j-i+1));
            i = j+1;
            result.push_back(s.substr(j+1, length));
            i = i+length;
        }
        return result;
    }
};
