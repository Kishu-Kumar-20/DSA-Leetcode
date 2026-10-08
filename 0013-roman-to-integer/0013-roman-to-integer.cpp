class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        // if(n == 1){
        //     return mp.find(s[0])->second;
        // }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == n-1){
                ans += mp.find(s[i])->second;
                continue;
            }
            char c1 = s[i], c2 = s[i+1];
            int v1 = mp.find(c1)->second, v2 = mp.find(c2)->second;
            if(v1 >= v2 ) ans+= v1;
            else{
                ans -= v1;
            }
        }
        return ans;
    }
};