class Solution {
public:
    int bouquets(vector<int> &arr, int k, int d,int m){
        int count = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= d){
                count++;
            }else{
                ans += count/k;
                count = 0;
            }
            if(ans >= m) return ans;
        }
        ans += count/k;
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long req = (long long)m*k;
        if(req > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = low +(high-low)/2;
            int num = bouquets(bloomDay, k, mid, m);
            if(num < m){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};