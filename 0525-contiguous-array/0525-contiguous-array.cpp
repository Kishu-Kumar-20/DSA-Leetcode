class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int, int> hash;
        hash[0] = -1;
        int sum = 0, len = 0;
        for(int i = 0; i< n; i++){
            if(nums[i] == 0) nums[i] = -1;
        }
        for(int i = 0; i < n; i++){
            sum += nums[i];
            // int x = 
            if(hash.find(sum) != hash.end()){
                len = max(len, (i-hash[sum]));
            }
            if(hash.find(sum) == hash.end()){
                hash[sum] = i;
            }
        }
        return len;
    }
};