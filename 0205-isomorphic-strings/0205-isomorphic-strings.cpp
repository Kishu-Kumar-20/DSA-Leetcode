class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hash1, hash2;
        for(int i = 0; i< s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];
            if(hash1.count(c1) && hash1[c1] != c2) return false;
            if(hash2.count(c2) && hash2[c2] != c1) return false;

            hash1[c1] = c2;
            hash2[c2] = c1;
        }
        return true;
    }
};