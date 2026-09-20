class Solution {
public:
    int reverseDegree(string s) {
        int i = 0;
        int sum = 0;
        while(i < s.length()){
            int rev = 122-s[i]+1;
            sum += rev*(i+1);
            i++;
        }
        return sum;
    }
};