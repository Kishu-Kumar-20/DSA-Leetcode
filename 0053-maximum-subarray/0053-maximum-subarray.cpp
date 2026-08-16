class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0, _max = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            _max = max(sum, _max);
            if(sum <0) sum = 0;
        }
        return _max;
    }
};