class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = left + (right - left)/2;
            if(kTest(mid, piles, h)) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    bool kTest(int k, vector<int>& piles, int h){
        int hours = 0; 
        for(int p: piles){
            hours += ceil(static_cast<double>(p)/k);
        }
        return hours<=h;
    }
};
