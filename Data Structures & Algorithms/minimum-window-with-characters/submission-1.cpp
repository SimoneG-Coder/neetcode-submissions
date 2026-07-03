class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> debt(128,0);
        int left=0, startIdx=-1, minLength=INT_MAX, remDebt=t.length();
        for(char c:t)debt[c]++;
        for(int right=0; right<s.length(); right++){
            if(debt[s[right]]>0)remDebt--;
            debt[s[right]]--;
            while(remDebt==0){
                if(right-left+1<minLength){
                    minLength = right-left+1;
                    startIdx = left;
                }
                debt[s[left]]++;
                if(debt[s[left]]>0)remDebt++;
                left++;
            }
        }
        return startIdx==-1?"":s.substr(startIdx,minLength);
    }
};
