class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int min = (int)(nums.size()/3) + 1;
        for(auto it: nums){
            mpp[it]++;
            if(mpp[it] == min){
                ans.push_back(it);
            }
            if(ans.size() == 2) break;
        }
        return ans;
    }
};