class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fs = 0, ts = 0, tzs = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                fs++;
            }else if(bills[i] == 10){
                if(fs == 0) return false;
                fs--;
                ts++;
            }else{
                tzs++;
                if(ts){
                    if(!fs) return false;
                    ts--;
                    fs--;
                }else{
                    if(fs<3) return false;
                    fs -= 3;
                }
            }
        }
        return true;
    }
};