class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int c_0 = 0, c_1 = 0, c_2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) c_0++;
            else if (nums[i] == 1) c_1++;
            else c_2++;
        }
        for (int i = 0; i< n; i++){
            if(i < c_0) nums[i] = 0;
            else if(i < c_0 + c_1) nums[i] = 1;
            else nums[i] = 2; 
        }
        
    }
};