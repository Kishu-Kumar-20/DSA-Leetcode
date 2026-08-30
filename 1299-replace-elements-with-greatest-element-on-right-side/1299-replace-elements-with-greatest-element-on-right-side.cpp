class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        int greatest = -1;
        for(int i = arr.size()-1; i >=0; i--){
            ans.insert(ans.begin(), greatest);
            if(greatest < arr[i]){
                greatest = arr[i];
            }
        }
        return ans; 
    }
};