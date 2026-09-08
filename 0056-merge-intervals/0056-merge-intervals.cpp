class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int left = intervals[i][0];
            int right = intervals[i][1];
            if(ans.empty() || ans.back()[1] < left){
                ans.push_back({left,right});
            }else{
                ans.back()[1] = max(ans.back()[1], right);
            }
        }
        return ans;
    }
};