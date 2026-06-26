class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l = 0;
        unordered_set<char> charSet;
        for(int r=0; r<s.length(); r++){
            while(charSet.count(s[r])){
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            maxLength = max(maxLength, r-l+1);
        }
        return maxLength;
    }
};
