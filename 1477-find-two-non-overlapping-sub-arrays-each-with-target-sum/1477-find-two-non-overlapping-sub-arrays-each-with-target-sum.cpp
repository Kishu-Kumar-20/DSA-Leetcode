class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int n = arr.size();
        vector<int> best(n, INT_MAX);
        int sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            // Carry forward the previous best
            if (i > 0)
                best[i] = best[i - 1];
            // Check if a subarray ending at i has sum = target
            if (mpp.find(sum - target) != mpp.end()) {
                int l = mpp[sum - target];
                int len = i - l;
                // Previous subarray must be completely before l+1
                if (l >= 0 && best[l] != INT_MAX) {
                    ans = min(ans, len + best[l]);
                }
                // This can become the best subarray
                best[i] = min(best[i], len);
            }
            // Store prefix sum
            mpp[sum] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};