class Solution {
public:
    int binarysearch(vector<int> &arr, int low, int high, int target){
        if(low >high) return -1;
        int mid = low + (high-low)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target){
            return binarysearch(arr, low, mid-1, target);
        }else{
            return binarysearch(arr, mid+1, high, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size()-1, target);
    }
};