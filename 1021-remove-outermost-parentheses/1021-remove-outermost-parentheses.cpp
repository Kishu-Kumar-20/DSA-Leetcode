class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;
        for(auto c:s){
            if(c == '(') count++;
            if(count > 1) ans = ans+c;
            if(c == ')') count--;
        }
        return ans;
    }
};