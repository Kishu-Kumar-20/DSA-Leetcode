class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int index = 0, ans = 1;
        for(int i = 0; i < n; i++){
            int x = i, y = i;
            while(x >= 0 && y < n && (s[x] == s[y])){
                if(ans < y-x+1){
                    ans = max(ans, y-x+1);
                    index = x;
                }
                x--;
                y++;
            }
            x = i;
            y = i+1;
            while(x >= 0 && y < n && (s[x] == s[y])){
                if(ans < y-x+1){
                    ans = max(ans, y-x+1);
                    index = x;
                }
                x--;
                y++;
            }
        }
        return s.substr(index, ans);
    }
};