class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long _sum = 0, _max = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            _sum += nums[i];
            _max = max(_sum, _max);
            _sum = max(_sum, 0LL);
        }
        return _max;
    }
};