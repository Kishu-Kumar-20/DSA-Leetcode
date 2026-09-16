class Solution {
public:
    long long sumofdiv(vector<int> &arr, int divisor, int num){
        long long res = 0;
        for(int i = 0; i < arr.size(); i++){
            res += (arr[i]-1 + divisor)/divisor;
            if(res > num) return res; 
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = low +(high-low)/2;
            int num = sumofdiv(nums, mid, threshold);
            if(num <= threshold){
                high = mid-1;
                ans = min(ans, mid);
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};