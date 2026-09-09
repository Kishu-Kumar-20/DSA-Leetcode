class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        int n = nums.size();
        int _xor = 0;
        int count = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
            _xor ^= count; 
            _xor ^= nums[i][j];
            count++;
            }
        }
        int result = _xor;
        int pos=0;
        while((result & (1 << pos)) == 0){
            pos++;
        }
        int x1 = 0, x2 = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j< n; j++){
                if((1 << pos) & nums[i][j]){
                    x1= x1^nums[i][j];
                }else{
                    x2= x2^nums[i][j];
                }
            }
        }
        for(int i = 1; i<=n*n; i++){
            if((1 << pos) & (i)){
                x1= x1^i;
            }else{
                x2= x2^i;
            }
        }
        int cnt = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j <n; j++){
                if(nums[i][j] == x1) cnt++;
            }
        }
        if(cnt == 2) return {x1, x2};
        else return {x2, x1};
    }
};