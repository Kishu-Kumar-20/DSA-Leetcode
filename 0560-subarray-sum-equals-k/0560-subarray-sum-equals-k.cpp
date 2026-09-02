class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long , int> summap;
        int sum = 0;
        int count = 0, n = nums.size();
        summap[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            // if(sum == k){
            //     count+=1;
            // }
            int num = sum-k;
            count += summap[num];
            summap[sum]+=1;
        }
        return count;
    }
};