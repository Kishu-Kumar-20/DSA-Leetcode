class Solution {
public:
    long long caltime(vector<int> &arr, int r, int h){
        long long time = 0;
        for(int i = 0; i < arr.size(); i++){
            time += (arr[i] + r - 1) / r; 
            
            if (time > h)
                return time;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            long long time = caltime(piles, mid, h);
            if(time <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};