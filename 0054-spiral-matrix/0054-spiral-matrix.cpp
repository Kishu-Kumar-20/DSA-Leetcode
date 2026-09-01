class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m-1, t = 0, b = n-1;
        vector<int> ans;
        int value = n*m, cnt = 0;
        while(cnt < value){
            for(int i = l; i <= r; i++){
                ans.push_back(matrix[t][i]);
                cnt++;
            }
            t++;
            for(int j = t; j <= b; j++){
                ans.push_back(matrix[j][r]);
                cnt++;
            }
            r--;
            if(cnt == value) break;
            for(int i = r; i >= l; i--){
                ans.push_back(matrix[b][i]);
                cnt++;

            }
            b--;
            if(cnt == value) break;
            for(int j = b; j >= t; j--){
                ans.push_back(matrix[j][l]);
                cnt++;
            }
            l++;
        }
        return ans;
    }
};