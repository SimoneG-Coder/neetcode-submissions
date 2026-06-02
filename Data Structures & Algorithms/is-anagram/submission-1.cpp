class Solution {
public:
//LOGIC: count the frequencies of each letter in a string using a vector of size 26
    bool isAnagram(string s, string t) {
        //since anagram is just a rearrangement of letters, the length of the 2 strings must be same. 
        if(s.length()!=t.length())return false;
        //initialise a vector of size 26(all alphabets) with 0(otherwise increment and decrement not posible) to keep track of letters in both string
        vector<int> count(26,0);
        for(int i=0; i<s.length(); i++){
            //use -'a' to reach the required block of vector(eg ascii(a)-ascii(a) = 0(a is the 0th index of the vector))
            count[s[i]-'a']++;    //increment a block of vector if its letter is in s
            count[t[i]-'a']--;    //decrement a block of vector if its letter is in t
        }
        for(int val: count){
            //all of the elements of the vector will be 0 if the strings are anagrams
            if(val!=0)return false;
        }
        return true;
    }
};
