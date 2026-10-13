class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n,0);
        for(int i = 0; i < n;i++){
            if(nums[i]<0) nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n/2+1; i++){
            if(2*i < n) temp[2*i] = nums[n - i - 1];
            if (2*i + 1 < n) temp[2*i + 1] = nums[i];
        }
        long long ans = 0;
        for(int i= 0; i<n; i=i+2){
            ans+=temp[i]*temp[i];
            if(i+1 <n) ans-=temp[i+1]*temp[i+1];
        }
        return ans;
    }
};