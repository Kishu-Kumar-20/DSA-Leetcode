class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_multimap<long long, int> summap;
        int sum = 0;
        int count = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum == k){
                count+=1;
            }
            int num = sum-k;
            if(summap.find(num) != summap.end()){
                int a = summap.count(num);
                count+=a;
            }
            summap.insert({sum, i});
        }
        return count;
    }
};