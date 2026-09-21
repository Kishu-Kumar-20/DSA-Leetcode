class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        if(len%2 == 1) return false;
        int i = 0;
        while (i < len){
            char c = s[i];          
            if(c == ')' && !st.empty()){
                if(st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }
            }else if( c == ']' && !st.empty()){
                if(st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }else if( c == '}' && !st.empty()){
                if(st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }else
                st.push(c);
            i++;
        }
        if(!st.empty()) return false;
        return true;
    }
};