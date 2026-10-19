class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(low == nums.size() || (nums[low] != target)) return ans;
        for(int i = low; i < high; i++) ans.push_back(i);
        return ans;
    }
};