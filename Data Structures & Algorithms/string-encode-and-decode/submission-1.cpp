class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string str: strs){
            //put the length(after converting to string) using to_string() + '#' + the string together
            encoded += to_string(str.length()) + '#' + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
            int i=0; 
            while(i<s.length()){
                int j=i;
                //use j to get the length of the upcoming string which is till before #
                while(s[j]!='#'){
                    j++;
                }
                //convert the length in string to intger using stoi()
                //substr(start position, number of elements) to egt substring
                int length = stoi(s.substr(i, j-i));
                //then place i to the position at the first letter of the string
                i = j+1;
                decoded.push_back(s.substr(i, length));
                //place i at the start of another length
                i += length;
            }
            return decoded;
    }
};
