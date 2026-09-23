class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int size = num.length();
        int i = size - 1;
        while( i >= 0){
            char c = num[i]; 
            if((int(c)-48)%2 == 1) {
                return num.substr(0,i+1);
            }
            i--;
        }
        return ans;
    }
};