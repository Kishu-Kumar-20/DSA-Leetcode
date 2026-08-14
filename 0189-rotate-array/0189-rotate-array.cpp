#include <algorithm>
class Solution {
public:
    void _reverse(vector<int> &arr, int i, int j){
            reverse(arr.begin()+i, arr.begin()+j+1);
        }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        _reverse(nums, 0, n-1);
        _reverse(nums, 0, k-1);
        _reverse(nums, k, n-1);
        
    }
};