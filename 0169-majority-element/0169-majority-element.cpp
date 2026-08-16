class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, ele;
        for(int i = 0; i<n; i++){
            if(count == 0){
                ele = nums[i];
                count++;
            }
            else if(ele == nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        int cnt = 0;
        for(int i = 0; i<n ; i++){
            if(ele == nums[i]) cnt++;
        }
        if(cnt > n/2) return ele;
        // return ele;
        return -1;
    }
};