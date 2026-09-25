class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 != n2) return false;
        for(int i = 0; i < n1; i++){
            if(t.find(s[i]) == string::npos) return false;
            t[t.find(s[i])] = '0';
        }
        return true;
    }
};