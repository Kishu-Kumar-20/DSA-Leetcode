class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0, odd = -1;
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
        if(odd == -1 || even == 0) return true;

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 == 0){

            }else{
                if((nums1[i]-odd) <= 0){
                    f_e = 0;
                }
            }
            if(nums1[i]%2 != 0){

            }else{
                if((nums1[i]-odd) <= 0){
                    f_o = 0;
                }
            }
        }
    
        if(f_o || f_e) return true;
        else return false;
    }
};