class Solution {
public:
    int rowno(vector<vector<int>> &arr, int n, int m){
        int max = 0;
        int ind = -1;
        for(int i = 0; i < n; i++){
            if(arr[i][m] > max){
                max = arr[i][m];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low+high)/2;
            int row = rowno(mat, n, mid);
            int left = mid-1 >= 0? mat[row][mid-1] : -1;
            int right = mid+1 < m? mat[row][mid+1] : -1;
            int value = mat[row][mid];
            if(value > left && value > right){
                return {row, mid};
            }else if(value < left){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return {-1, -1};
    }
};