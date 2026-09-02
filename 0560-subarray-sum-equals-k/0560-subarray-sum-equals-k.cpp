class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long , int> summap;
        int sum = 0;
        int count = 0, n = nums.size();
        summap.insert({sum,1});
        for(int i = 0; i < n; i++){
            sum += nums[i];
            // if(sum == k){
            //     count+=1;
            // }
            int num = sum-k;
            if(summap.find(num) != summap.end()){
                int a = summap[num];
                count+=a;
            }
            if(summap.find(sum) == summap.end()) summap.insert({sum, 1});
            else summap[sum]++;
        }
        return count;
    }
};