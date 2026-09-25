class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long ele =1;
        int row = rowIndex;
        for(int c = 1; c <= rowIndex+1; c++){
            ans.push_back(ele);
            ele = (long long)(ele) * row--;
            ele = ele/c;
        }
        return ans;
    }
};