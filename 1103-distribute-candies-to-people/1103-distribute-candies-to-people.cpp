class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> temp(num_people, 0);

        int give = 0;
        int idx = 0;
        while (candies > 0) {
            give++;
            candies -= give;
            temp[idx % num_people] += give;
            idx++;
        }
        if (candies < 0) {
            idx--;
            temp[idx % num_people] +=candies;
        }
        return temp;
    }
};