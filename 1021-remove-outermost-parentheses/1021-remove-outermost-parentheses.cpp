class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans; 
        ans.reserve(s.size());
        int count = 0;
        for(auto c:s){
            if(c == '(') count++;
            if(count > 1) ans.push_back(c);
            if(c == ')') count--;
        }
        return ans;
    }
};