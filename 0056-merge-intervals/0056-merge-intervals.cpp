class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int left = intervals[i][0];
            int right = intervals[i][1];
            int j = i+1;
            while(j<n && intervals[j][0] <= right){
                right = max(right, intervals[j][1]);
                j++;
            }
            vector<int> temp = {left, right};
            ans.push_back(temp);
            i = --j;
        }
        return ans;
    }
};