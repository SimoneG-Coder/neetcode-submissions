class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left=0;
        int maxLength = 0;
        for(int right=0; right<s.length(); right++){
            count[s[right]-'A']++;
            int currentMaxFreq = 0;
            for(int i=0; i<26; i++){
                currentMaxFreq = max(currentMaxFreq, count[i]);
            }
            int windowSize = right - left + 1;
            if(windowSize-currentMaxFreq > k){
                count[s[left]-'A']--;
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};
