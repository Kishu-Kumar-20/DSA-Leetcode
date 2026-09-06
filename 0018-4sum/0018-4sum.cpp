class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            for(int j = i+1; j < n; j++){
                unordered_set<long long> hash;
                for(int k = j+1; k< n;k++){
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    long long forth = target - sum;
                    if(hash.find(forth) != hash.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int) (forth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};