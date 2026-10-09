class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int flag = -1;
        int count = 0, signcnt = 0;
        for(auto c:s){
            if((count!=0 && (c == '-' || c == '+')) || signcnt > 1) break;
            if(c == ' '){
                if(count != 0) break;
                else if(signcnt >0) break;
                else continue;
            }
            else if(c == '-') {
                flag = 1;
                signcnt++;
            }
            else if(c == '+') {
                flag = 0;
                signcnt++;
            }
            else if(c >= '0' && c <= '9') {
                ans = ans*10 + int(c-'0');
                count++;
            }
            else if(c < '0' || c > '9') break;
            if(ans > INT_MAX) break;
        }
        if(flag == 1) ans = -ans;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return ans;
    }
};