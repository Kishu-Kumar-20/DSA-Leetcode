class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i  <= numRows; i++){
            vector<int> temp;
            int ele = 1;
            int row = i-1; 
            for(int col = 1; col <= i; col++){
                temp.push_back(ele);
                ele = ele * row--;
                ele = ele / col;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};