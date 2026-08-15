class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<long, int> mpp;
       int n = nums.size();
       vector<int> ans;
       for(int i = 0; i < n; i++){
            int num = target-nums[i];
            if(mpp.find(num) != mpp.end()){
                ans.push_back((*mpp.find(num)).second);
                ans.push_back(i);
                break;
            }
            mpp[nums[i]] = i;
       }
       return ans; 
    }
};