class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> hash;
        unordered_map<char,int> mpp;
        for(int i = 0; i < s.length(); i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            char c = it.first;
            int freq = it.second;
            hash.push({freq,c});
        }
        string ans = "";
        while(!hash.empty()){
            int len = hash.top().first;
            char x = hash.top().second;
            for(int j = 0; j < len; j++){
                ans+=x;
            }
            hash.pop();
        }
        return ans; 
    }
};