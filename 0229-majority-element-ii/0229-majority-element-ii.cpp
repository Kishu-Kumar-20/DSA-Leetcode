class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0;
        int ele1, ele2;
        for(int i = 0; i < nums.size(); i++){
            if(cnt1 ==0 && nums[i] != ele2){
                ele1 = nums[i];
                cnt1++;
            }else if(cnt2 ==0 && nums[i] != ele1){
                ele2 = nums[i];
                cnt2++;
            }else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int mini = nums.size()/3 +1;
        cnt1 = 0, cnt2 = 0;
        for(auto it: nums){
            if(it== ele1) cnt1++;
            else if(it == ele2) cnt2++;
        }
        if(cnt1 >= mini) ans.push_back(ele1);
        if(cnt2 >= mini) ans.push_back(ele2);
        return ans;
    }
};