class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int size = num.length();
        int i = size - 1;
        while( i >= 0){
            char c = num[i]; 
            if((int(c)-48)%2 == 1) {
                for(int j = 0; j < i+1 ; j++){
                    ans+=num[j];
                }
                break;
            }
            i--;
        }
        return ans;
    }
};