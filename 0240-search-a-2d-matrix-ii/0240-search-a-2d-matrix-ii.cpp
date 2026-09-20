class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = m-1;
        while(row < n && col >= 0){
            int ele = matrix[row][col];
            if(ele == target) return true;
            else if(ele > target) col--;
            else row++;
        }
        return false;
    }
};