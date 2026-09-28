class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int len = s.length();
        int i = 0, ans = 0;
        while (i < len){
            char c = s[i];          
            if(c == ')'){
                ans = max(ans, (int)st.size());
                st.pop();
            }else if(c == '('){
                st.push(c);
            }
            i++;
        }
        return ans;
    }
};