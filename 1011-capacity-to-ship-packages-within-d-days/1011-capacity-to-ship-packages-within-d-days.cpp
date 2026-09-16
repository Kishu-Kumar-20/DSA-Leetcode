class Solution {
public:
    long long duration(vector<int> &arr, int r, int limit){
        int sum = 0;
        long long day = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if (sum == r){
                sum = 0;
                day++;
            }else if (sum > r){
                day++;
                sum = arr[i];
            }
            if(day > limit) return day;
        }
        if(sum != 0) day++;
        return day;
    } 
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        while(low <= high){
            int mid = low + (high - low)/2;
            int time = duration(weights, mid, days);
            if(time <= days){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};