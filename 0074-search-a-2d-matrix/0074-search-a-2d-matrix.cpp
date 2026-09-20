class Solution {
public:
    bool bs(vector<int> &nums, int x){
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == x) return true;
            else if(nums[mid] > x) high = mid-1; 
            else low = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            int leftm = matrix[mid][0], rightm = matrix[mid][m-1];
            if(leftm <= target && target <= rightm){
                return bs(matrix[mid], target);
            }else if(leftm > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};