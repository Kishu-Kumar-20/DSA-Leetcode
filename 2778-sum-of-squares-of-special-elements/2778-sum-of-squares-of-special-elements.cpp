class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> factors;
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                factors.push_back(i);
                if(i != n/i) factors.push_back(n/i);
            }
        }
        for(auto i : factors){
            sum+=nums[i-1]*nums[i-1];
        }
        return sum;
    }
};