class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long _sum = 0, _max = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            _sum += nums[i];
            _max = max(_sum, _max);
            if(_sum < 0) _sum = 0;
        }
        return _max;
    }
};