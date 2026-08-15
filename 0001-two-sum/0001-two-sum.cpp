class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<long, int> mpp;
       int n = nums.size();
       vector<int> ans;
       for(int i = 0; i < n; i++){
            int num = target-nums[i];
            auto it = mpp.find(num);
            if(it != mpp.end()){
                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]] = i;
       }
       return {}; 
    }
};