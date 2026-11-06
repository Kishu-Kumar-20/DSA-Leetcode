class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_ind = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(max_ind < i) return false;
            max_ind = max(max_ind, i+nums[i]);
        }
        return true;
    }
};