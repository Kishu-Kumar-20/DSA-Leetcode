class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, odd = -1;
        vector<int> v;
        int f_o = 1, f_e = 1;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 == 0){
                if(even == 0) even = nums1[i];
                even = min(even, nums1[i]);
            }else{
                if(odd == -1) odd = nums1[i];
                odd = min(nums1[i],odd);
            }
        }
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 == 0){
                continue;
            }else{
                if(odd == INT_MAX || ((nums1[i]-odd)%2 == 0)){
                    f_e = 0;
                    break;
                }
            }
        }
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 != 0){
                continue;
            }else{
                if(even == INT_MIN || ((nums1[i]-odd)%2 != 1)){
                    f_o = 0;
                }
            }
        }
        if(f_o || f_e) return true;
        else return false;
    }
};