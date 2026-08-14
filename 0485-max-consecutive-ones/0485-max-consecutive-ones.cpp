class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int _max = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }
                _max = max(_max,count);
            if(nums[i]!= 1){
                count = 0;
            }
        }
        return _max;
    }
};