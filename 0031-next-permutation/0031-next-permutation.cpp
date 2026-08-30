class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = -1, len = nums.size();
        for(int i = len-2; i >=0; i--){
            if(nums[i] < nums[i+1]){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = len-1; i >= pos; i--){
            if(nums[i] > nums[pos]){
                swap(nums[i], nums[pos]);
                break;
            }
        }
        reverse(nums.begin() + pos+1, nums.end());
    }
};