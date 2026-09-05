class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stack(n);
        int top = -1;
        for(int i = n-1; i>=0; i--){
            if(i == n-1){
                top++;
                stack[top] = nums[i];
            }else if(nums[i] <= stack[top]){
                top++;
                stack[top] = nums[i];
            } 
        }
        int _max = 0;
        for(int i = 0; i < n; i++){
            _max = max(_max, nums[i]);
            if(_max-stack[top] <= k) return i;
            if(nums[i] == stack[top]){
                top--;
            } 
        }
        return -1;
    }
};