class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int longest = 1;
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it-1) != st.end()) continue;
            int cur_cnt = 1;
            int num = it;
            while(st.find(num+1)!= st.end()){
                cur_cnt++;
                num++;
            }
            longest = max(longest, cur_cnt);
        }
        return longest;
    }
};