class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;
        for(auto c : s){
            if(c == ')'){
                ans = max(ans, depth);
                depth--;
            }else if(c == '('){
                depth++;
            }
        }
        return ans;
    }
};