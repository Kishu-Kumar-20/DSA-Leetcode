class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> st;
        unordered_set<int> st_notsp;
        int not_sp = 0;
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
            }else{
                if(nums[i] != nums[i-1]){
                    if(st_notsp.find(nums[i]) == st_notsp.end()) not_sp++;
                    st_notsp.insert(nums[i]);
                }
            }
        }
        return st.size()-not_sp;
    }
};