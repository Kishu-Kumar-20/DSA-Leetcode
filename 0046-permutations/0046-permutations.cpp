class Solution {
public:
    void allperm(vector<int> nums, vector<vector<int>> &ans, vector<int> &freq, vector<int> &add){
        if(add.size() == nums.size()){
            ans.push_back(add);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(!freq[i]){
                add.push_back(nums[i]);
                freq[i] = 1;
                allperm(nums, ans, freq, add);
                freq[i] = 0;
                add.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> freq (nums.size(), 0);
        vector<int> add;
        allperm(nums, ans, freq, add);
        return ans;
    }
};