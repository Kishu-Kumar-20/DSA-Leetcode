class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        // while(i < haystack.length() && j < needle.length()){
        //     char c1 = haystack[i];
        //     char c2 = needle[j];
        //     if(c1 == c2){
        //         j++;
        //     }else {
        //         j = 0;
        //     }
        //     i++;
        //     if(j == needle.length()){
        //         return i - needle.length();
        //     }
        // }
        if(haystack.find(needle) != string::npos) return haystack.find(needle);
        return -1;
    }
};