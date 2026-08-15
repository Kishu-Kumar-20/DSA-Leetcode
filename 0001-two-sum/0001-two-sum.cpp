class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<long, int> mpp;
       int n = nums.size();
       for(int i = 0; i < n; i++){
            int num = target-nums[i];
            auto it = mpp.find(num);
            if(it != mpp.end()){
                return {it->second, i};
            }
            mpp[nums[i]] = i;
       }
       return {}; 
    }
};