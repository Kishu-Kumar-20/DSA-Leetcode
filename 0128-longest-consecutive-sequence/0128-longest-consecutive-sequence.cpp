class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int longest = 1;
        int cur_cnt = 0;
        int lastsmallest = INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]-1 == lastsmallest){
                cur_cnt++;
            }else if (nums[i] == lastsmallest){

            }else{
                cur_cnt = 1;
            }
            lastsmallest = nums[i];
            longest = max(longest, cur_cnt);
        }
        return longest;
    }
};