class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums){
        int n = nums.size();
        if(n == 0|| n == 1) return n;
        int linc = 1, ldec = 1;
        int inc = 1, dec = 1;
        for(int i = 0; i < n-1; i++){
            if(nums[i]>nums[i+1]){
                dec++;
            }else{
                ldec = max(dec,ldec);
                dec = 1;
            }
            if(nums[i]<nums[i+1]){
                inc++;
            }else{
                linc = max(linc,inc);
                inc = 1;
            }
        }
        ldec = max(dec,ldec);
        linc = max(linc,inc);
        return (linc>ldec?linc:ldec);
    }
};