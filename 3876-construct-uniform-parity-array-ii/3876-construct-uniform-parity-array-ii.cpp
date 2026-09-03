class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = INT_MIN, odd = INT_MAX;
        vector<int> v;
        int f_o = 1, f_e = 1;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 == 0){
                if(even == INT_MIN) even = nums1[i];
                even = min(even, nums1[i]);
            }else odd = min(nums1[i],odd);
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