class Solution {
public:
vector<int> generaterows(int n){
    vector<int> temp;
    int ele = 1;
    int row = n-1; 
    for(int col = 1; col <= n; col++){
        temp.push_back(ele);
        ele = ele * row--;
        ele = ele / col;
    }
    return temp;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i  <= numRows; i++){
            ans.push_back(generaterows(i));
        }
        return ans;
    }
};