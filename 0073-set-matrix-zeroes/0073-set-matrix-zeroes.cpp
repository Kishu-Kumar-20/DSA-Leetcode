class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int col_0 = 1;
        for(int i = 0; i <m ; i++){
            for(int j = 0; j < n; j++){
                if(nums[i][j] == 0){
                    nums[i][0] = 0;
                    if(j == 0){ 
                        col_0 = 0;
                    }else {
                        nums[0][j] = 0;
                    }
                }
            }
        }
        for(int i = m-1; i >=1 ; i--){
            for(int j = n-1; j >= 1; j--){
                if(nums[i][0] == 0 || nums[0][j] == 0){
                    nums[i][j] = 0;
                }
            }
        }
        for(int i = n-1; i >= 1; i--){
            if(nums[0][0] == 0){
                nums[0][i] = 0;
            }
            // else{
                // break;
            // }
        }
        for(int i = m-1; i >= 0; i--){
            if(col_0 == 0 ){
                nums[i][0] = 0;
            }
            // else{
                // break;
            // }
        }
    }
};