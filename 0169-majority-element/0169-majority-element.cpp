class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, ele = nums[0];
        for(int i = 0; i<n; i++){
            if(ele == nums[i]){
                count++;
            }
            else count--;
            if(count == 0){
                ele = nums[i+1];
            }
        }
        return ele;
    }
};