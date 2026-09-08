class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = n-1, i = m-1, p = n+m-1;
        while(i>-1 && j >-1){
            if(nums1[i] <= nums2[j]){
                nums1[p--] = nums2[j--];
            }else{
                nums1[p--] = nums1[i--];
            }
        }
        if(j == -1) return;
        else{
            while(j >-1){
                nums1[p--] = nums2[j--];
            }
        }
    }
};