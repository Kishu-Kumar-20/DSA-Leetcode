class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int nearest = -1, dis_min = INT_MAX;
        int t_x = target[0], t_y = target[1];
        for(int i = 0; i < n; i++){
            int dis = (abs(t_x-drones[i][0])+abs(t_y-drones[i][1]));
            if(dis <= drones[i][2]){
                if(dis<dis_min){
                    nearest = i;
                    dis_min = dis;
                }
            }
        }
        return nearest;
    }
};