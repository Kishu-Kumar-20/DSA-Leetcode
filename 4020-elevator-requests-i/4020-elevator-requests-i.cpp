class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
    int time =requests[0];
    for(int i = 0; i<requests.size()-1; i++){
        time += abs(requests[i]-requests[i+1]);
    }
    return time;    
    }
};