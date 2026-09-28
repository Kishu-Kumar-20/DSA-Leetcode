class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char,char> hash1, hash2;
        for(int i = 0; i< n; i++){
            char c1 = s[i];
            char c2 = t[i];
            if(hash1.find(c1) != hash1.end() && hash2.find(c2) != hash2.end()){
                auto x = hash1.find(c1);
                auto y = hash2.find(c2);
                if(x->second != c2 || y->second != c1) return false;
            }else if(hash1.find(c1) == hash1.end() && hash2.find(c2) == hash2.end()){
                hash1[c1] = c2;
                hash2[c2] = c1;
            }else{
                return false;
            }
        }
        return true;
    }
};